//===- Addr.hpp -------------------------------------------------*- C++ -*-===//
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
#ifndef GTIRB_ADDR_H
#define GTIRB_ADDR_H

#include <gtirb/Export.hpp>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iosfwd>
#include <optional>

/// \file Addr.hpp
/// \brief Class gtirb::Addr and related functions.

namespace gtirb {
/// \brief A special class to store an Effective Address.
///
/// It is a thin wrapper around a uint64_t for 64-bit address storage. Its
/// semantics in overflow situations are the same as semantics for unsigned
/// integers.
///
/// An Addr cannot store a relative address as it cannot contain a negative
/// number.
class GTIRB_EXPORT_API Addr {
public:
  /// \brief The underlying type used to represent an Addr object.
  typedef uint64_t value_type;
  /// \brief The type used to represent a difference between two Addr objects.
  typedef int64_t difference_type;

  /// \brief Default constructor.
  constexpr Addr() noexcept : Address{0} {}

  /// \brief Explicit conversion from \c value_type to \ref Addr.
  ///
  /// \param X The address.
  constexpr explicit Addr(value_type X) noexcept : Address(X) {}

  /// \brief Explicitly convert \ref Addr to \c value_type.
  ///
  /// \return An integer representation of the \ref Addr.
  constexpr explicit operator value_type() const noexcept { return Address; }

  /// \brief Unary plus for \ref Addr. This is a noop because Addr objects
  /// represent an unsigned address value.
  ///
  /// \return A copy of the implicit \ref Addr.
  constexpr Addr operator+() const noexcept { return Addr(+Address); }

  /// \brief Unary complement for \ref Addr. Flips the value of all bits in
  /// the address.
  ///
  /// \return A copy of the implicit \ref Addr object, with all bits flipped.
  constexpr Addr operator~() const noexcept { return Addr(~Address); }

  /// \brief Preincrement for \ref Addr.
  ///
  /// \return The incremented \ref Addr.
  constexpr Addr& operator++() noexcept {
    ++Address;
    return *this;
  }

  /// \brief Postincrement for \ref Addr.
  ///
  /// \return A new \ref Addr representing the address prior to being
  /// incremented.
  constexpr Addr operator++(int) noexcept {
    Addr R(*this);
    ++Address;
    return R;
  }

  /// \brief Predecrement for \ref Addr.
  ///
  /// \return The decremented \ref Addr.
  constexpr Addr& operator--() noexcept {
    --Address;
    return *this;
  }

  /// \brief Postdecrement for \ref Addr.
  ///
  /// \return A new \ref Addr representing the address prior to being
  /// decremented.
  constexpr Addr operator--(int) noexcept {
    Addr R(*this);
    --Address;
    return R;
  }

  /// \brief Binary + operator for \ref Addr + integral offset.
  ///
  /// \param A        The \ref Addr operand to +.
  /// \param Offset   The offset to add to \p A.
  ///
  /// \return A new \ref Addr representing \p A + \p Offset.
  friend constexpr Addr operator+(const Addr& A, value_type Offset) noexcept {
    return Addr(A.Address + Offset);
  }

  /// \brief Binary + operator for integral offset + \ref Addr.
  ///
  /// \param Offset   The offset to add to \p A.
  /// \param A        The \ref Addr operand to +.
  ///
  /// \return A new \ref Addr representing \p A + \p Offset.
  friend constexpr Addr operator+(value_type Offset, const Addr& A) noexcept {
    return A + Offset;
  }

  /// \brief Add-assign for \ref Addr.
  ///
  /// \param Offset   The offset to add to the represented address.
  ///
  /// \return \c *this
  constexpr Addr& operator+=(value_type Offset) noexcept {
    Address += Offset;
    return *this;
  }

  /// \brief Binary - operator for \ref Addr - integral offset.
  ///
  /// \param A        The \ref Addr operand to -.
  /// \param Offset   The offset to subtract from \p A.
  ///
  /// \return A new \ref Addr representing  \p A - \p Offset.
  ///
  /// NB: There is no overload for Offset - Addr like there is for Offset + Addr
  /// because subtraction is not associative like addition is.
  friend constexpr Addr operator-(const Addr& A, value_type Offset) noexcept {
    return Addr(A.Address - Offset);
  }

  /// \brief Subtract-assign for \ref Addr.
  ///
  /// \param Offset   The offset to subtract from the represented address.
  ///
  /// \return \c *this
  constexpr Addr& operator-=(value_type Offset) noexcept {
    Address -= Offset;
    return *this;
  }

  /// \brief Binary - operator for \ref Addr - \ref Addr.
  ///
  /// \param A        The minuend.
  /// \param B        The subtrahend.
  ///
  /// \return         The difference \p A - \p B. NB: this is a difference type
  /// and not a valid address.
  friend constexpr difference_type operator-(const Addr& A,
                                             const Addr& B) noexcept {
    return static_cast<difference_type>(A.Address - B.Address);
  }

  /// \brief Equality operator for \ref Addr.
  friend constexpr bool operator==(const Addr& LHS, const Addr& RHS) noexcept {
    return LHS.Address == RHS.Address;
  }

  /// \brief Inquality operator for \ref Addr.
  friend constexpr bool operator!=(const Addr& LHS, const Addr& RHS) noexcept {
    return !operator==(LHS, RHS);
  }

  /// \brief Less-than operator for \ref Addr.
  friend constexpr bool operator<(const Addr& LHS, const Addr& RHS) noexcept {
    return LHS.Address < RHS.Address;
  }

  /// \brief Greater-than operator for \ref Addr.
  friend constexpr bool operator>(const Addr& LHS, const Addr& RHS) noexcept {
    return operator<(RHS, LHS);
  }

  /// \brief Less-than-or-equal operator for \ref Addr.
  friend constexpr bool operator<=(const Addr& LHS, const Addr& RHS) noexcept {
    return !operator<(RHS, LHS);
  }

  /// \brief Greater-than-or-equal operator for \ref Addr.
  friend constexpr bool operator>=(const Addr& LHS, const Addr& RHS) noexcept {
    return !operator<(LHS, RHS);
  }

private:
  value_type Address{0};
};

/// \brief A range of addresses.
class GTIRB_EXPORT_API AddrRange {
public:
  /// \brief Construct a range starting at \p Lower, extending up to, but not
  /// including, \p Upper.
  ///
  /// Ranges cannot have negative size, so `AddrRange(Addr(20), Addr(10))`
  /// creates a range starting at `Addr(20)` with size 0.
  ///
  /// \param Lower  first address in the range.
  /// \param Upper  address after the last address contained in the range.
  constexpr explicit AddrRange(Addr Lower, Addr Upper) noexcept
      : First(Lower), Size(Upper - (Lower < Upper ? Lower : Upper)) {}

  /// \brief Construct a range starting at \p Lower and containing a total of
  /// \p Count addresses.
  ///
  /// \param Lower  first address in the range.
  /// \param Count  number of addresses in the range.
  constexpr explicit AddrRange(Addr Lower, uint64_t Count) noexcept
      : First(Lower), Size(Count) {}

  /// \brief Equality operator for \ref AddrRange.
  constexpr bool operator==(const AddrRange& RHS) const noexcept {
    return First == RHS.First && Size == RHS.Size;
  }

  /// \brief Inequality operator for \ref AddrRange.
  constexpr bool operator!=(const AddrRange& RHS) const noexcept {
    return First != RHS.First || Size != RHS.Size;
  }

  /// \brief Inclusive lower bound of the address range.
  constexpr Addr lower() const noexcept { return First; }

  /// \brief Exclusive upper bound of the address range.
  constexpr Addr upper() const noexcept { return First + Size; }

  /// \brief Number of addresses in the range.
  constexpr uint64_t size() const noexcept { return Size; }

private:
  /// \brief The first address in the range.
  Addr First;

  /// \brief The number of bytes in the range.
  uint64_t Size;
};

template <typename T> std::optional<uint64_t> asOptionalSize(T X);

template <> std::optional<uint64_t> inline asOptionalSize(uint64_t X) {
  return X;
}

template <>
std::optional<uint64_t> inline asOptionalSize(std::optional<uint64_t> X) {
  return X;
}

/// \relates Addr
/// \brief Address range of an object.
///
/// \tparam T         Any type that specifies a range of addresses via
/// getAddress() and getSize() methods (e.g., DataBlock).
///
/// \param Object     The object to interrogate.
///
/// \return An address range (\ref AddrRange) [L, H) such that all and only the
/// addresses L <= A < H are in \p Object, or \c std::nullopt if the object's
/// addresses are not defined.
template <typename T> std::optional<AddrRange> addressRange(const T& Object) {
  if (std::optional<Addr> A = Object.getAddress()) {
    if (std::optional<uint64_t> S = Object.getSize()) {
      return AddrRange{*A, *S};
    }
  }
  return std::nullopt;
}

/// \relates Addr
/// \brief Exclusive upper limit of an object's address range.
///
/// \tparam T         Any type that specifies a range of addresses via
/// getAddress() and getSize() methods (e.g. DataBlock).
///
/// \param Object     The object to interrogate.
///
/// \return An address (\ref Addr) A such that A-1 is in \p Object and
/// A is not.
template <typename T> std::optional<Addr> addressLimit(const T& Object) {
  auto A = Object.getAddress();
  auto B = asOptionalSize(Object.getSize());
  if (A && B) {
    return *A + *B;
  }
  return std::nullopt;
}

/// \relates Addr
/// \brief Check: Does the specified object contain the specified address?
///
/// \tparam T      Any type that specifies a range of addresses via
/// getAddress() and getSize() methods (e.g. DataBlock).
///
/// \param Object  The object of interest.
/// \param Ea      The address of interest.
///
/// \return \c true if \p Ea is in the address range of \p Object, \c
/// false otherwise.
template <typename T> bool containsAddr(const T& Object, Addr Ea) {
  return Object.getAddress() <= Ea && addressLimit(Object) > Ea;
}

/// \relates Addr
/// \brief Writes an address to an output stream in hex.
///
/// This is a convenience, since this seems to be the format that is most
/// commonly used. Note that other formats can be used by casting the address
/// to a \c uint64_t and setting the formatting explicilty.
///
/// \param Stream  the stream to write to.
/// \param A       the address to write.
///
/// \return Stream.
template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits>& Stream, Addr A) {
  auto Flags = Stream.flags();
  Stream << std::setbase(16) << std::showbase << static_cast<uint64_t>(A);
  Stream.flags(Flags);
  return Stream;
}

/// \relates Addr
/// \brief Writes an optional address to an output stream in hex.
///
/// This is a convenience to unwrap an Addr stored in a std::optional. If the
/// optional does not hold a valid Addr object, then <none> is printed to the
/// stream.
///
/// \param Stream  the stream to write to.
/// \param A       the optional address to write.
///
/// \return Stream.
template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits>& Stream, std::optional<Addr> A) {
  if (A)
    return Stream << *A;
  return Stream << "<none>";
}

} // namespace gtirb

namespace std {

/// \brief Hash operation for \ref Addr.
template <> struct hash<gtirb::Addr> {
  size_t operator()(const gtirb::Addr& A) const {
    return std::hash<uint64_t>{}(static_cast<uint64_t>(A));
  }
};

} // namespace std

#endif // GTIRB_ADDR_H
