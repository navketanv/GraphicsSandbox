#pragma once
#include "GraphicsCore/Enums.h"
#include <type_traits>

namespace util {

template<typename T>
struct EnableBitMaskOperators : std::false_type
{
};

template<>
struct EnableBitMaskOperators<GraphicsCore::BufferBit> : std::true_type
{
};

} // namespace util

template<typename T>
    requires util::EnableBitMaskOperators<T>::value
constexpr T operator|(T lhs, T rhs) noexcept {
    using U = std::underlying_type_t<T>;
    return static_cast<T>(static_cast<U>(lhs) | static_cast<U>(rhs));
}

template<typename T>
    requires util::EnableBitMaskOperators<T>::value
constexpr T& operator|=(T& lhs, T rhs) noexcept {
    using U = std::underlying_type_t<T>;
    lhs = static_cast<T>(static_cast<U>(lhs) | static_cast<U>(rhs));
    return lhs;
}

template<typename T>
    requires util::EnableBitMaskOperators<T>::value
constexpr T operator&(T lhs, T rhs) noexcept {
    using U = std::underlying_type_t<T>;
    return static_cast<T>(static_cast<U>(lhs) & static_cast<U>(rhs));
}

template<typename T>
    requires util::EnableBitMaskOperators<T>::value
constexpr T& operator&=(T& lhs, T rhs) noexcept {
    using U = std::underlying_type_t<T>;
    lhs = static_cast<T>(static_cast<U>(lhs) & static_cast<U>(rhs));
    return lhs;
}

template<typename T>
    requires util::EnableBitMaskOperators<T>::value
constexpr bool hasFlag(T value, T flag) noexcept {
    return ((value & flag) == flag);
}
