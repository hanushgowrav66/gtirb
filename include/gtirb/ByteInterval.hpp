//===- ByteInterval.hpp -----------------------------------------*- C++ -*-===//
//
//  Copyright (C) 2020 GrammaTech, Inc.
//
//  This code is licensed under the MIT license. See the LICENSE file in the
//  project root for license terms.
//
//  This project is sponsored by the Office of Naval Research, One Liberty
//  Center, 875 N. Randolph Street, Arlington, VA 22203 under contract #
//  N68335-17-C-0700.  The content of the information does not necessarily
//  reflect the position or policy of the Government and no official
//  endorsement should be inferred.
//
//===----------------------------------------------------------------------===//

#ifndef GTIRB_BYTE_INTERVAL_H
#define GTIRB_BYTE_INTERVAL_H

#include <gtirb/ByteVector.hpp>
#include <gtirb/CodeBlock.hpp>
#include <gtirb/DataBlock.hpp>
#include <gtirb/Node.hpp>
#include <gtirb/SymbolicExpression.hpp>
#include <boost/iterator/filter_iterator.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/key_extractors.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/range/iterator_range.hpp>
#include <map>
#include <optional>
#include <variant>
#include <vector>

/// \file ByteInterval.hpp
/// \brief Class gtirb::ByteInterval.

namespace proto {
class ByteInterval;
} // namespace proto

namespace gtirb {
class Section; // Forward declared for the backpointer.

/// \class ByteInterval
///
/// \brief A contiguous region of bytes in a binary.
///
/// A ByteInterval defines a relative ordering for a group of \ref Block
/// objects, optionally at a fixed address in memory. It also stores the bytes
/// associated with these blocks.
///
/// If two blocks are in two different ByteIntervals, then it should be
/// considered safe (that is, preserving of program semantics) to move one block
/// relative to the other in memory. If two blocks are in the same ByteInterval,
/// then it should be considered unknown if moving the two blocks relative to
/// one another in memory is a safe operation.
class GTIRB_EXPORT_API ByteInterval : public Node {
  /// \class Block
  ///
  /// \brief A node (either a \ref CodeBlock or \ref DataBlock), alongside an
  /// offset, held within this interval.
  struct Block {
    uint64_t Offset;
    gtirb::Node* Node;

    Block(uint64_t Off, gtirb::Node* N) : Offset(Off), Node(N) {}

    /// \brief Get the offset from the beginning of this block's \ref
    /// ByteInterval.
    uint64_t getOffset() const { return Offset; }

    /// \brief Get the \ref Node, either a \ref CodeBlock or \ref DataBlock, in
    /// the \ref ByteInterval.
    ///
    /// This function returns a nonconst pointer despite being const
    /// because it's valid to mutate the nodes, but not valid to mutate the
    /// block-offset pairs in the BlockSet.
    gtirb::Node* getNode() const { return Node; }
  };

  /// \class BlockKindEquals
  ///
  /// \brief A predicate object to discern one type of block.
  ///
  /// This predicate does not interact with the subclassing system;
  /// BlockKindEquals<Node::Kind::CfgNode> will not identify any blocks as CFG
  /// nodes, for example.
  template <Node::Kind K> struct BlockKindEquals {
    bool operator()(const Block& B) const {
      return B.getNode()->getKind() == K;
    }
  };

  /// \class BlockToNode
  ///
  /// \brief A function for a transform iterator to turn blocks into nodes.
  template <typename NodeType> struct BlockToNode {
    NodeType& operator()(const Block& B) const {
      return *cast<NodeType>(B.Node);
    }
  };

  struct by_offset {};
  struct by_pointer {};
  using BlockSet = boost::multi_index::multi_index_container<
      Block, boost::multi_index::indexed_by<
                 boost::multi_index::ordered_non_unique<
                     boost::multi_index::tag<by_offset>,
                     boost::multi_index::const_mem_fun<Block, uint64_t,
                                                       &Block::getOffset>>,
                 boost::multi_index::hashed_unique<
                     boost::multi_index::tag<by_pointer>,
                     boost::multi_index::const_mem_fun<Block, Node*,
                                                       &Block::getNode>>>>;
  using SymbolicExpressionMap = std::map<uint64_t, SymbolicExpression>;

  /// \brief Get the \ref Block that corresponds to a \ref Node.
  const Block& nodeToBlock(const Node* N) const {
    auto& Index = Blocks.get<by_pointer>();
    auto It = Index.find(const_cast<Node*>(N));
    assert(It != Index.end() &&
           "ByteInterval::nodeToBlock called with block not in interval");
    return *It;
  }

  /// \brief Call this function when \ref Bytes changes size from any source
  /// other than \ref setSize, in order to update indices and the like.
  void updateSize() { setSize(Bytes.getSize()); }

public:
  /// \brief Create a ByteInterval object.
  ///
  /// \param C         The \ref Context in which this interval will be held.
  /// \param Size      The size of this interval in bytes.
  /// \param InitSize  The number of bytes with initialized values. Defaults
  ///                  to the value of Size.
  /// \return          The newly created ByteInterval.
  static ByteInterval* Create(Context& C, uint64_t Size = 0,
                              std::optional<uint64_t> InitSize = std::nullopt) {
    return C.Create<ByteInterval>(C, std::nullopt, InitSize.value_or(Size),
                                  Size);
  }

  /// \brief Create a ByteInterval object.
  ///
  /// \param C         The \ref Context in which this interval will be held.
  /// \param Address   An (optional) fixed address for this interval.
  /// \param Size      The size of this interval in bytes.
  /// \param InitSize  The number of bytes with initialized values. Defaults
  ///                  to the value of Size.
  /// \return          The newly created ByteInterval.
  static ByteInterval* Create(Context& C, std::optional<Addr> Address,
                              uint64_t Size = 0,
                              std::optional<uint64_t> InitSize = std::nullopt) {
    return C.Create<ByteInterval>(C, Address, InitSize.value_or(Size), Size);
  }

  /// \brief Create a ByteInterval object.
  ///
  /// \tparam InputIterator An input iterator yielding bytes.
  /// \param C          The \ref Context in which this interval will be held.
  /// \param BytesBegin The start of the range to copy to the byte vector.
  /// \param BytesEnd   The end of the range to copy to the byte vector.
  /// \param Size       The size of this interval in bytes. Defaults to the
  ///                   size of the range of bytes. If specified, either
  ///                   trucates the range of bytes given or pads it at the end
  ///                   with zeroes.
  /// \param InitSize   The number of bytes with initialized values. Defaults to
  ///                   the size of the range of bytes. If specified, does NOT
  ///                   zero out values from the range past this number.
  /// \return           The newly created ByteInterval.
  template <typename InputIterator>
  static ByteInterval* Create(Context& C, InputIterator Begin,
                              InputIterator End,
                              std::optional<uint64_t> Size = std::nullopt,
                              std::optional<uint64_t> InitSize = std::nullopt) {
    return C.Create<ByteInterval>(
        C, std::nullopt, InitSize ? *InitSize : std::distance(Begin, End),
        Begin, End, Size ? *Size : std::distance(Begin, End));
  }

  /// \brief Create a ByteInterval object.
  ///
  /// \tparam InputIterator An input iterator yielding bytes.
  /// \param C          The \ref Context in which this interval will be held.
  /// \param Address    An (optional) fixed address for this interval.
  /// \param BytesBegin The start of the range to copy to the byte vector.
  /// \param BytesEnd   The end of the range to copy to the byte vector.
  /// \param Size       The size of this interval in bytes. Defaults to the
  ///                   size of the range of bytes. If specified, either
  ///                   trucates the range of bytes given or pads it at the end
  ///                   with zeroes.
  /// \param InitSize   The number of bytes with initialized values. Defaults to
  ///                   the size of the range of bytes. If specified, does NOT
  ///                   zero out values from the range past this number.
  /// \return           The newly created ByteInterval.
  template <typename InputIterator>
  static ByteInterval* Create(Context& C, std::optional<Addr> Address,
                              InputIterator Begin, InputIterator End,
                              std::optional<uint64_t> Size = std::nullopt,
                              std::optional<uint64_t> InitSize = std::nullopt) {
    return C.Create<ByteInterval>(
        C, Address, InitSize ? *InitSize : std::distance(Begin, End), Begin,
        End, Size ? *Size : std::distance(Begin, End));
  }

  /// \brief Get the \ref Section this byte interval belongs to.
  Section* getSection() { return Parent; }
  /// \brief Get the \ref Section this byte interval belongs to.
  const Section* getSection() const { return Parent; }

  /// \brief Get the fixed address of this interval, if present.
  ///
  /// If this field is present, it may indicate the original address at which
  /// this interval was located at in memory, or it may indicate that this
  /// block's address is fixed and must not be changed. If this field is not
  /// present, it indicates that the interval is free to be moved around in
  /// memory while preserving program semantics.
  std::optional<Addr> getAddress() const { return Address; }

  /// \brief Get the size of this interval in bytes.
  ///
  /// If this number is greater than the value returned by \ref
  /// getInitializedSize, this indicates that the high addresses taken up by
  /// this interval consist of uninitialized bytes. This often occurs in BSS
  /// sections, where data is zero-initialized rather than stored as zeroes in
  /// the binary.
  uint64_t getSize() const { return Bytes.getSize(); }

  /// \brief Iterator over \ref Block objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using blocks_iterator =
      boost::transform_iterator<BlockToNode<Node>,
                                BlockSet::index<by_offset>::type::iterator>;
  /// \brief Range of \ref Block objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using blocks_range = boost::iterator_range<blocks_iterator>;
  /// \brief Const iterator over \ref Block objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using const_blocks_iterator = boost::transform_iterator<
      BlockToNode<const Node>,
      BlockSet::index<by_offset>::type::const_iterator>;
  /// \brief Const range of \ref Block objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using const_blocks_range = boost::iterator_range<const_blocks_iterator>;

  /// \brief Return an iterator to the first \ref Block.
  blocks_iterator blocks_begin() { return blocks_iterator(Blocks.begin()); }
  /// \brief Return a const iterator to the first \ref Block.
  const_blocks_iterator blocks_begin() const {
    return const_blocks_iterator(Blocks.begin());
  }
  /// \brief Return an iterator to the element following the last \ref Block.
  blocks_iterator blocks_end() { return blocks_iterator(Blocks.end()); }
  /// \brief Return a const iterator to the element following the last
  /// \ref Block.
  const_blocks_iterator blocks_end() const {
    return const_blocks_iterator(Blocks.end());
  }
  /// \brief Return a range of the \ref Block objects in this interval.
  blocks_range blocks() {
    return boost::make_iterator_range(blocks_begin(), blocks_end());
  }
  /// \brief Return a const range of the \ref Block objects in this interval.
  const_blocks_range blocks() const {
    return boost::make_iterator_range(blocks_begin(), blocks_end());
  }

  /// \brief Iterator over \ref CodeBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using code_blocks_iterator = boost::transform_iterator<
      BlockToNode<CodeBlock>,
      boost::filter_iterator<BlockKindEquals<Node::Kind::CodeBlock>,
                             BlockSet::index<by_offset>::type::iterator>>;
  /// \brief Range of \ref CodeBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using code_blocks_range = boost::iterator_range<code_blocks_iterator>;
  /// \brief Const iterator over \ref CodeBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using const_code_blocks_iterator = boost::transform_iterator<
      BlockToNode<const CodeBlock>,
      boost::filter_iterator<BlockKindEquals<Node::Kind::CodeBlock>,
                             BlockSet::index<by_offset>::type::const_iterator>>;
  /// \brief Const range of \ref CodeBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using const_code_blocks_range =
      boost::iterator_range<const_code_blocks_iterator>;

  /// \brief Return an iterator to the first \ref CodeBlock.
  code_blocks_iterator code_blocks_begin() {
    return code_blocks_iterator(
        code_blocks_iterator::base_type(Blocks.begin(), Blocks.end()));
  }
  /// \brief Return a const iterator to the first \ref CodeBlock.
  const_code_blocks_iterator code_blocks_begin() const {
    return const_code_blocks_iterator(
        const_code_blocks_iterator::base_type(Blocks.begin(), Blocks.end()));
  }
  /// \brief Return an iterator to the element following the last \ref
  /// CodeBlock.
  code_blocks_iterator code_blocks_end() {
    return code_blocks_iterator(
        code_blocks_iterator::base_type(Blocks.end(), Blocks.end()));
  }
  /// \brief Return a const iterator to the element following the last \ref
  /// CodeBlock.
  const_code_blocks_iterator code_blocks_end() const {
    return const_code_blocks_iterator(
        const_code_blocks_iterator::base_type(Blocks.end(), Blocks.end()));
  }
  /// \brief Return a range of the \ref CodeBlock objects in this interval.
  code_blocks_range code_blocks() {
    return boost::make_iterator_range(code_blocks_begin(), code_blocks_end());
  }
  /// \brief Return a const range of the \ref CodeBlock objects in this
  /// interval.
  const_code_blocks_range code_blocks() const {
    return boost::make_iterator_range(code_blocks_begin(), code_blocks_end());
  }

  /// \brief Iterator over \ref DataBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using data_blocks_iterator = boost::transform_iterator<
      BlockToNode<DataBlock>,
      boost::filter_iterator<BlockKindEquals<Node::Kind::DataBlock>,
                             BlockSet::index<by_offset>::type::iterator>>;
  /// \brief Range of \ref DataBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using data_blocks_range = boost::iterator_range<data_blocks_iterator>;
  /// \brief Const iterator over \ref DataBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using const_data_blocks_iterator = boost::transform_iterator<
      BlockToNode<const DataBlock>,
      boost::filter_iterator<BlockKindEquals<Node::Kind::DataBlock>,
                             BlockSet::index<by_offset>::type::const_iterator>>;
  /// \brief Const range of \ref DataBlock objects.
  ///
  /// Blocks are yielded in offset order, ascending. If two blocks have the
  /// same offset, thier order is not specified.
  using const_data_blocks_range =
      boost::iterator_range<const_data_blocks_iterator>;

  /// \brief Return an iterator to the first \ref DataBlock.
  data_blocks_iterator data_blocks_begin() {
    return data_blocks_iterator(
        data_blocks_iterator::base_type(Blocks.begin(), Blocks.end()));
  }
  /// \brief Return a const iterator to the first \ref DataBlock.
  const_data_blocks_iterator data_blocks_begin() const {
    return const_data_blocks_iterator(
        const_data_blocks_iterator::base_type(Blocks.begin(), Blocks.end()));
  }
  /// \brief Return an iterator to the element following the last \ref
  /// DataBlock.
  data_blocks_iterator data_blocks_end() {
    return data_blocks_iterator(
        data_blocks_iterator::base_type(Blocks.end(), Blocks.end()));
  }
  /// \brief Return a const iterator to the element following the last \ref
  /// DataBlock.
  const_data_blocks_iterator data_blocks_end() const {
    return const_data_blocks_iterator(
        const_data_blocks_iterator::base_type(Blocks.end(), Blocks.end()));
  }
  /// \brief Return a range of the \ref DataBlock objects in this interval.
  data_blocks_range data_blocks() {
    return boost::make_iterator_range(data_blocks_begin(), data_blocks_end());
  }
  /// \brief Return a const range of the \ref DataBlock objects in this
  /// interval.
  const_data_blocks_range data_blocks() const {
    return boost::make_iterator_range(data_blocks_begin(), data_blocks_end());
  }

  /// \brief Iterator over \ref SymbolicExpression objects.
  ///
  /// Results are yielded in offset order, ascending.
  using symbolic_expressions_iterator = SymbolicExpressionMap::iterator;
  /// \brief Range of \ref SymbolicExpression objects.
  ///
  /// Results are yielded in offset order, ascending.
  using symbolic_expressions_range =
      boost::iterator_range<symbolic_expressions_iterator>;
  /// \brief Const iterator over \ref SymbolicExpression objects.
  ///
  /// Results are yielded in offset order, ascending.
  using const_symbolic_expressions_iterator =
      SymbolicExpressionMap::const_iterator;
  /// \brief Const range of \ref SymbolicExpression objects.
  ///
  /// Results are yielded in offset order, ascending.
  using const_symbolic_expressions_range =
      boost::iterator_range<const_symbolic_expressions_iterator>;

  /// \brief Return an iterator to the first \ref SymbolicExpression.
  symbolic_expressions_iterator symbolic_expressions_begin() {
    return SymbolicExpressions.begin();
  }
  /// \brief Return a const iterator to the first \ref SymbolicExpression.
  const_symbolic_expressions_iterator symbolic_expressions_begin() const {
    return SymbolicExpressions.begin();
  }
  /// \brief Return an iterator to the element following the last \ref
  /// SymbolicExpression.
  symbolic_expressions_iterator symbolic_expressions_end() {
    return SymbolicExpressions.end();
  }
  /// \brief Return a const iterator to the element following the last \ref
  /// SymbolicExpression.
  const_symbolic_expressions_iterator symbolic_expressions_end() const {
    return SymbolicExpressions.end();
  }
  /// \brief Return a range of the \ref SymbolicExpression objects in this
  /// interval.
  symbolic_expressions_range symbolic_expressions() {
    return boost::make_iterator_range(symbolic_expressions_begin(),
                                      symbolic_expressions_end());
  }
  /// \brief Return a const range of the \ref SymbolicExpression objects in this
  /// interval.
  const_symbolic_expressions_range symbolic_expressions() const {
    return boost::make_iterator_range(symbolic_expressions_begin(),
                                      symbolic_expressions_end());
  }

  /// \brief Remove a block from this interval.
  ///
  /// \tparam BlockType   Either \ref CodeBlock or \ref DataBlock.
  /// \param  N           The block to remove.
  ///
  /// \return Whether or not the operation succeeded. This operation can
  /// fail if the node to remove is not actually part of this node to begin
  /// with.
  template <class BlockType> bool removeBlock(BlockType* N) {
    N->removeFromIndices();
    auto& Index = Blocks.get<by_pointer>();
    if (auto Iter = Index.find(N); Iter != Index.end()) {
      Index.erase(Iter);
      N->setByteInterval(nullptr);
      return true;
    }
    return false;
  }

  /// \brief Move an existing Block to be a part of this interval.
  ///
  /// \tparam BlockType   Either \ref CodeBlock or \ref DataBlock.
  /// \param  Off           The offset to move the block to.
  /// \param  N           The block to move.
  template <typename BlockType>
  BlockType* addBlock(uint64_t Off, BlockType* N) {
    if (N->getByteInterval()) {
      N->getByteInterval()->removeBlock(N);
    }

    N->setByteInterval(this);
    Blocks.emplace(Off, N);
    N->addToIndices();
    return N;
  }

  /// \brief Adds a new \ref SymbolicExpression to this interval.
  ///
  /// \param  Off       The offset to add the new \ref SymbolicExpression at.
  /// \param  SymExpr   An existing \ref SymbolicExpression to copy into this
  ///                   interval.
  /// \return           The newly created \ref SymbolicExpression.
  SymbolicExpression& addSymbolicExpression(uint64_t Off,
                                            const SymbolicExpression& SymExpr) {
    this->mutateIndices([&]() { SymbolicExpressions.emplace(Off, SymExpr); });
    return SymbolicExpressions[Off];
  }

  /// \brief Removes a \ref SymbolicExpression at the given offset, if present.
  ///
  /// \param Off  The offset of the \ref SymbolicExpression to remove.
  ///
  /// \return Whether or not the operation succeeded. This operation can
  /// fail if the node to remove is not actually part of this node to begin
  /// with.
  bool removeSymbolicExpression(uint64_t Off) {
    std::size_t N;
    this->mutateIndices([&]() { N = SymbolicExpressions.erase(Off); });
    return N != 0;
  }

  /// \brief Get the symbolic expression at the given offset, if present.
  ///
  /// \param Off  The offset of the \ref SymbolicExpression to return.
  /// \return   The \ref SymbolicExpression at that offset, or nullptr if there
  ///           is no \ref SymbolicExpression at that offset.
  SymbolicExpression* getSymbolicExpression(uint64_t Off) {
    if (auto It = SymbolicExpressions.find(Off);
        It != SymbolicExpressions.end()) {
      return &It->second;
    }
    return nullptr;
  }

  /// \brief Get the symbolic expression at the given offset, if present.
  ///
  /// \param Off  The offset of the \ref SymbolicExpression to return.
  /// \return   The \ref SymbolicExpression at that offset, or nullptr if there
  ///           is no \ref SymbolicExpression at that offset.
  const SymbolicExpression* getSymbolicExpression(uint64_t Off) const {
    if (auto It = SymbolicExpressions.find(Off);
        It != SymbolicExpressions.end()) {
      return &It->second;
    }
    return nullptr;
  }

  /// \brief Set or clear the address of this interval.
  ///
  /// \param A  Either the new address, or an empty \ref std::optional if you
  ///           wish to remove the address.
  void setAddress(std::optional<Addr> A) {
    this->mutateIndices([this, A]() { Address = A; });
  }

  /// \brief Set the size of this interval.
  ///
  /// This will also adjust \ref getInitializedSize if the size given is less
  /// than the initialized size.
  ///
  /// \param S  The new size.
  void setSize(uint64_t S) {
    this->mutateIndices([this, S]() {
      InitializedSize = std::min(InitializedSize, S);

      Bytes.setSize(S);
    });
  }

  /// \brief Get the number of initialized bytes in this interval.
  ///
  /// Not all bytes in this interval may correspond to bytes physically stored
  /// in the underlying file format. This can occur, for example, in BSS
  /// sections, which are zero-initialized at loadtime, but these zeroes are not
  /// stored in the file itself. If this number is smaller than the value
  /// returned by \ref getSize, this indicates that any bytes past this number
  /// are unitialized bytes with values determined at loadtime. As such, all
  /// bytes past this number in this interval's byte vector are truncated when
  /// saving to file.
  ///
  /// This number will never be larger than the value returned by \ref getSize.
  uint64_t getInitializedSize() const { return InitializedSize; }

  /// \brief Set the number of initialized bytes in this interval.
  ///
  /// Not all bytes in this interval may correspond to bytes physically stored
  /// in the underlying file format. This can occur, for example, in BSS
  /// sections, which are zero-initialized at loadtime, but these zeroes are not
  /// stored in the file itself. If this number is smaller than the value
  /// returned by \ref getSize, this indicates that any bytes past this number
  /// are unitialized bytes with values determined at loadtime. As such, all
  /// bytes past this number in this interval's byte vector are truncated when
  /// saving to file.
  ///
  /// If the number specified is larger than \ref getSize, then
  /// the byte vector is expanded with zeroes to be equal to the new allocated
  /// size.
  void setInitializedSize(uint64_t S) {
    if (S > getSize()) {
      setSize(S);
    }
    InitializedSize = S;
  }

  /// \brief The endianess of data: Either big or little-endian.
  using Endian = ByteVector::Endian;
  /// \brief Iterator over bytes in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  template <typename T> using bytes_iterator = ByteVector::iterator<T>;
  /// \brief Range over bytes in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  template <typename T> using bytes_range = ByteVector::range<T>;
  /// \brief Const tterator over bytes in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  template <typename T>
  using const_bytes_iterator = ByteVector::const_iterator<T>;
  /// \brief Const range over bytes in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  template <typename T> using const_bytes_range = ByteVector::const_range<T>;

  /// \brief Get an iterator to the first byte in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  ///
  /// \param  InputOrder  The endianess of the data in the interval.
  /// \param  OutputOrder The endianess you wish to read out from the interval.
  template <typename T>
  bytes_iterator<T> bytes_begin(Endian InputOrder = Endian::native,
                                Endian OutputOrder = Endian::native) {
    return Bytes.begin<T>(InputOrder, OutputOrder);
  }

  /// \brief Get an iterator past the last byte in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  ///
  /// \param  InputOrder  The endianess of the data in the interval.
  /// \param  OutputOrder The endianess you wish to read out from the interval.
  template <typename T>
  bytes_iterator<T> bytes_end(Endian InputOrder = Endian::native,
                              Endian OutputOrder = Endian::native) {
    return Bytes.end<T>(InputOrder, OutputOrder);
  }

  /// \brief Get a range of all data in this interval's byte vector.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  ///
  /// \param  InputOrder  The endianess of the data in the interval.
  /// \param  OutputOrder The endianess you wish to read out from the interval.
  template <typename T>
  bytes_range<T> bytes(Endian InputOrder = Endian::native,
                       Endian OutputOrder = Endian::native) {
    return Bytes.bytes<T>(InputOrder, OutputOrder);
  }

  /// \brief Get an iterator to the first byte in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  ///
  /// \param  InputOrder  The endianess of the data in the interval.
  /// \param  OutputOrder The endianess you wish to read out from the interval.
  template <typename T>
  const_bytes_iterator<T>
  bytes_begin(Endian InputOrder = Endian::native,
              Endian OutputOrder = Endian::native) const {
    return Bytes.begin<T>(InputOrder, OutputOrder);
  }

  /// \brief Get an iterator past the last byte in this interval.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  ///
  /// \param  InputOrder  The endianess of the data in the interval.
  /// \param  OutputOrder The endianess you wish to read out from the interval.
  template <typename T>
  const_bytes_iterator<T> bytes_end(Endian InputOrder = Endian::native,
                                    Endian OutputOrder = Endian::native) const {
    return Bytes.end<T>(InputOrder, OutputOrder);
  }

  /// \brief Get a range of all data in this interval's byte vector.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type that satisfies Boost's EndianReversible concept.
  ///
  /// \param  InputOrder  The endianess of the data in the interval.
  /// \param  OutputOrder The endianess you wish to read out from the interval.
  template <typename T>
  const_bytes_range<T> bytes(Endian InputOrder = Endian::native,
                             Endian OutputOrder = Endian::native) const {
    return Bytes.bytes<T>(InputOrder, OutputOrder);
  }

  /// \brief Insert data into this interval's byte vector.
  ///
  /// This function only alters bytes in the vector; it does not adjust the
  /// offsets of any blocks or symbolic expressions that may be effected by this
  /// change.
  ///
  /// \tparam T   The type of data you wish to insert into the byte vector. Must
  /// be a POD type that satisfies Boost's EndianReversibleInplace concept.
  ///
  /// \tparam InputIterator  The type of an input iterator yielding T.
  ///
  /// \param  Pos           The position in the byte vector to insert data at.
  /// \param  Begin         The start of the data to insert.
  /// \param  End           The end of the data to insert.
  /// \param  VectorOrder   The endianess of the data in the interval.
  /// \param  ElementsOrder The endianess of the data to be inserted.
  ///
  /// \return An iterator pointing to the first element inserted by this call.
  template <typename T, typename InputIterator>
  const_bytes_iterator<T> insertBytes(const_bytes_iterator<T> Pos,
                                      InputIterator Begin, InputIterator End,
                                      Endian VectorOrder = Endian::native,
                                      Endian ElementsOrder = Endian::native) {
    auto Result = Bytes.insert<T>(Pos, Begin, End, VectorOrder, ElementsOrder);
    updateSize();
    return Result;
  }

  /// \brief Erase data from this interval's byte vector.
  ///
  /// This function only alters bytes in the vector; it does not adjust the
  /// offsets of any blocks or symbolic expressions that may be effected by this
  /// change.
  ///
  /// \tparam T     The type of data you wish to erase.
  ///
  /// \param  Begin The start of the data to erase.
  /// \param  End   The end of the data to erase.
  ///
  /// \return An iterator pointing to the first element after those erased by
  /// this call.
  template <typename T>
  const_bytes_iterator<T> eraseBytes(const_bytes_iterator<T> Begin,
                                     const_bytes_iterator<T> End) {
    auto Result = Bytes.erase<T>(Begin, End);
    updateSize();
    return Result;
  }

  /// \brief Return the raw data underlying this interval's byte vector.
  ///
  /// Much like \ref std::vector::data, this function is low-level and
  /// potentially unsafe. This pointer refers to valid memory only where an
  /// iterator would be valid to point to. Modifying the size of the byte
  /// vector may invalidate this pointer. Any endian conversions will not be
  /// performed.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type.
  template <typename T> T* rawBytes() { return Bytes.data<T>(); }

  /// \brief Return the raw data underlying this interval's byte vector.
  ///
  /// Much like \ref std::vector::data, this function is low-level and
  /// potentially unsafe. This pointer refers to valid memory only where an
  /// iterator would be valid to point to. Modifying the size of the byte
  /// vector may invalidate this pointer. Any endian conversions will not be
  /// performed.
  ///
  /// \tparam T The type of data stored in this interval's byte vector. Must be
  /// a POD type.
  template <typename T> const T* rawBytes() const { return Bytes.data<T>(); }

  /// @cond INTERNAL
  /// \brief The protobuf message type used for serializing ByteInterval.
  using MessageType = proto::ByteInterval;

  /// \brief Serialize into a protobuf message.
  ///
  /// \param[out] Message   Serialize into this message.
  ///
  /// \return void
  void toProtobuf(MessageType* Message) const;

  /// \brief Construct a ByteInterval from a protobuf message.
  ///
  /// \param C  The Context in which the deserialized ByteInterval will be held.
  /// \param Message  The protobuf message from which to deserialize.
  ///
  /// \return The deserialized ByteInterval object, or null on failure.
  static ByteInterval* fromProtobuf(Context& C, Section* Parent,
                                    const MessageType& Message);

  /// \brief Populate symbolic expressions from a Protobuf message.
  ///
  /// \param C  The Context in which the deserialized SymbolicExpressions will
  /// be held.
  ///
  /// \param Message  The protobuf message from which to deserialize.
  void symbolicExpressionsFromProtobuf(Context& C, const MessageType& Message);

  static bool classof(const Node* N) {
    return N->getKind() == Kind::ByteInterval;
  }
  /// @endcond

private:
  ByteInterval(Context& C) : Node(C, Kind::ByteInterval) {}

  template <typename... Args>
  ByteInterval(Context& C, std::optional<Addr> A, uint64_t IS, Args... B)
      : Node(C, Kind::ByteInterval), Address(A), InitializedSize(IS),
        Bytes(B...) {}

  void setSection(Section* S) { Parent = S; }

  Section* Parent{nullptr};
  std::optional<Addr> Address;
  uint64_t InitializedSize{0};
  BlockSet Blocks;
  SymbolicExpressionMap SymbolicExpressions;
  ByteVector Bytes;

  friend class Context;   // Friend to enable Context::Create.
  friend class Section;   // Friend to enable Section::(re)moveByteInterval.
  friend class CodeBlock; // Friend to enable CodeBlock::getAddress.
  friend class DataBlock; // Friend to enable DataBlock::getAddress.

  // Friends to enable CodeBlock::bytes and DataBlock::bytes.
  friend GTIRB_EXPORT_API ByteVector& getByteVector(ByteInterval* BI);
  friend GTIRB_EXPORT_API const ByteVector&
  getByteVector(const ByteInterval* BI);
};
} // namespace gtirb

#endif // GTIRB_BYTE_INTERVAL_H
