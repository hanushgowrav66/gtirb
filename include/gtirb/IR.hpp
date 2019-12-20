//===- IR.hpp ---------------------------------------------------*- C++ -*-===//
//
//  Copyright (C) 2018-2019 GrammaTech, Inc.
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
#ifndef GTIRB_IR_H
#define GTIRB_IR_H

#include <gtirb/Addr.hpp>
#include <gtirb/AuxData.hpp>
#include <gtirb/AuxDataContainer.hpp>
#include <gtirb/Module.hpp>
#include <gtirb/Node.hpp>
#include <gtirb/version.h>
#include <boost/iterator/indirect_iterator.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/range/iterator_range.hpp>
#include <map>
#include <string>
#include <vector>

/// \file IR.hpp
/// \brief Class gtirb::IR.

namespace proto {
class IR;
}
namespace gtirb {
class Module;

/// @cond INTERNAL

/// \brief Update the lookup indices of an IR when a Module changes.
///
/// The IR has indices for fast lookup of certain module traits. When mutating
/// these traits, call this function, with your mutation code in a lambda.
/// if \ref Module::getIR returns null, then no update is performed, but the
/// lambda is still called.
///
/// \param M  The module you wish to mutate.
/// \param F  A function taking no arguments and retuning void. This function
/// should mutate M.
void GTIRB_EXPORT_API mutateIRIndices(Module* M,
                                      const std::function<void()>& F);
/// @endcond

/// \class IR
///
/// \brief A complete internal representation consisting of Modules
/// (\ref Module).
///
/// \dot
/// digraph example {
///     node [shape=record, fontname=Helvetica, fontsize=10];
///
///     ir [ label="IR" URL="\ref IR"];
///     module [ label="Module" URL="\ref Module"];
///     auxData [ label="AuxData" URL="\ref AuxData"];
///     imageByteMap [label="ImageByteMap" URL="\ref ImageByteMap"]
///     blocks [label="Block" URL="\ref Block"]
///     data [label="DataBlock"  URL="\ref DataBlock"]
///     symbolicExpressions  [label="SymbolicExpression"
///                           URL="\ref SymbolicExpression"]
///     sections [label="Section" URL="\ref Section"]
///     symbols [label="Symbol" URL="\ref Symbol"]
///     cfg [label="CFG" URL="\ref CFG"]
///
///     ir -> module;
///     ir -> auxData;
///     module -> cfg;
///     module -> data
///     module -> imageByteMap;
///     module -> sections
///     module -> symbols;
///     module -> symbolicExpressions
///     cfg -> blocks;
/// }
/// \enddot
///

// Examples
// The location for these is arbitrary as Doxygen puts all examples in a
// separate section.

/// \example data-symbols.cpp
/// Open an IR and print every symbol pointing to data.

/// \example cfg-paths.cpp
/// Open an IR and print every path from some point to some other point.

/// \example functions.cpp
/// Open an IR with function information in an auxiliary data store and print
/// every function along with the number of other functions it calls.

/// \example jumps.cpp
/// Open an IR and print the Address of every jump instruction,
/// along with the jump targets (if known).

/// \example data-symbols.py
/// Open an IR via protobuf and print every symbol pointing to data.

/// \example cfg-paths.py
/// Open an IR via protobuf and print every path from some point to some
/// other point.

/// \example datasymbols.java
/// Open an IR via protobuf and print every symbol pointing to data.

class GTIRB_EXPORT_API IR : public AuxDataContainer {
  IR(Context& C) : AuxDataContainer(C, Kind::IR) {}

  struct by_name {};
  struct by_pointer {};

  using ModuleSet = boost::multi_index::multi_index_container<
      Module*, boost::multi_index::indexed_by<
                   boost::multi_index::ordered_non_unique<
                       boost::multi_index::tag<by_name>,
                       boost::multi_index::const_mem_fun<
                           Module, const std::string&, &Module::getName>>,
                   boost::multi_index::hashed_unique<
                       boost::multi_index::tag<by_pointer>,
                       boost::multi_index::identity<Module*>>>>;

public:
  /// \brief Create an IR object in its default state.
  ///
  /// \param C  The Context in which this object will be held.
  ///
  /// \return The newly created object.
  static IR* Create(Context& C) { return C.Create<IR>(C); }

  /// \brief Iterator over \ref Module "Modules".
  ///
  /// Modules are returned in name order. If more than one module has the same
  /// name, the order in which they are returned is unspecified.
  using iterator = boost::indirect_iterator<ModuleSet::iterator>;
  /// \brief Constant iterator over \ref Module "Modules".
  ///
  /// Modules are returned in name order. If more than one module has the same
  /// name, the order in which they are returned is unspecified.
  using const_iterator =
      boost::indirect_iterator<ModuleSet::const_iterator, const Module>;

  /// \brief Returns an iterator to the first Module.
  iterator begin() { return Modules.begin(); }
  /// \brief Returns an iterator to the element following the last Module.
  iterator end() { return Modules.end(); }
  /// \brief Returns a constant iterator to the first Module.
  const_iterator begin() const { return Modules.begin(); }
  /// \brief Returns a constant iterator to the element following the last
  /// Module.
  const_iterator end() const { return Modules.end(); }

  /// \brief Range of \ref Module "Modules".
  ///
  /// Modules are returned in name order. If more than one module has the same
  /// name, the order in which they are returned is unspecified.
  using range = boost::iterator_range<iterator>;
  /// \brief Constant range of \ref Module "Modules".
  ///
  /// Modules are returned in name order. If more than one module has the same
  /// name, the order in which they are returned is unspecified.
  using const_range = boost::iterator_range<const_iterator>;

  /// \brief Returns a range of the \ref Module "Modules".
  range modules() { return boost::make_iterator_range(begin(), end()); }
  /// \brief Returns a constant range of the \ref Module "Modules".
  const_range modules() const {
    return boost::make_iterator_range(begin(), end());
  }

  /// \brief Remove a \ref Module object located in this IR.
  ///
  /// \param S The \ref Module object to remove.
  void removeModule(Module* S) {
    auto& Index = Modules.get<by_pointer>();
    if (auto Iter = Index.find(S); Iter != Index.end())
      Index.erase(Iter);
    S->setIR(nullptr);
  }

  /// \brief Move a \ref Module object to be located in this IR.
  ///
  /// \param S The \ref Module object to add.
  void moveModule(Module* S) {
    if (S->getIR()) {
      S->getIR()->removeModule(S);
    }
    Modules.emplace(S);
    S->setIR(this);
  }

  /// \brief Creates a new \ref Module in this IR.
  ///
  /// \tparam Args  The arguments to construct a \ref Module.
  template <typename... Args> Module* addModule(Context& C, Args... A) {
    auto* N = Module::Create(C, this, A...);
    Modules.emplace(N);
    return N;
  }

  /// \brief Serialize to an output stream in binary format.
  ///
  /// \param Out The output stream.
  ///
  /// \return void
  void save(std::ostream& Out) const;

  /// \brief Serialize to an output stream in JSON format.
  ///
  /// \param Out The output stream.
  ///
  /// \return void
  void saveJSON(std::ostream& Out) const;

  /// \brief Deserialize binary format from an input stream.
  ///
  /// \param C   The Context in which this IR will be loaded.
  /// \param In  The input stream.
  ///
  /// \return The deserialized IR object.
  static IR* load(Context& C, std::istream& In);

  /// \brief Deserialize JSON format from an input stream.
  ///
  /// \param C   The Context in which this IR will be loaded.
  /// \param In  The input stream.
  ///
  /// \return The deserialized IR object.
  static IR* loadJSON(Context& C, std::istream& In);

  /// \brief The protobuf message type used for serializing IR.
  using MessageType = proto::IR;

  /// \brief Serialize into a protobuf message.
  ///
  /// \param[out] Message   Serialize into this message.
  ///
  /// \return void
  void toProtobuf(MessageType* Message) const;

  /// \brief Construct a IR from a protobuf message.
  ///
  /// \param C   The Context in which the deserialized IR will be held.
  /// \param Message  The protobuf message from which to deserialize.
  ///
  /// \return The deserialized IR object, or null on failure.
  static IR* fromProtobuf(Context& C, const MessageType& Message);

  /// \cond INTERNAL
  static bool classof(const Node* N) { return N->getKind() == Kind::IR; }
  /// \endcond

  /// \brief Get the version of the Protobuf used when creating this IR.
  ///
  /// Backwards-incompatible changes to the Protobuf structure of GTIRB cause
  /// this verison number to increment.
  uint32_t getVersion() const { return Version; }

  /// \brief Set the version of the Protobuf used when creating this IR.
  ///
  /// Backwards-incompatible changes to the Protobuf structure of GTIRB cause
  /// this verison number to increment. This function is useful when, for
  /// example, migrating GTIRB from old versions to new versions of the Protobuf
  /// format.
  void setVersion(uint32_t V) { Version = V; }

private:
  ModuleSet Modules;
  uint32_t Version{GTIRB_PROTOBUF_VERSION};

  friend class Context; // Allow Context to construct new IRs.

  // Allow mutation of IR indices
  friend void GTIRB_EXPORT_API mutateIRIndices(Module* M,
                                               const std::function<void()>& F);
};
} // namespace gtirb

#endif // GTIRB_IR_H
