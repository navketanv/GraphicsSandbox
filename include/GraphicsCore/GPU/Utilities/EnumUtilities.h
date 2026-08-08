#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include "GraphicsCore/GPU/Types/Enums.h"

namespace GraphicsCore::GPU {

[[nodiscard]]
constexpr std::size_t sizeOf(VertexAttributeType type)
{
    switch (type) {
    case VertexAttributeType::eFloat:
        return sizeof(float);
    case VertexAttributeType::eUnsignedInt:
        return sizeof(std::uint32_t);
    case VertexAttributeType::eUnsignedByte:
        return sizeof(std::uint8_t);
    case VertexAttributeType::eInvalid:
        break;
    }
    std::unreachable();
}

[[nodiscard]]
constexpr std::size_t sizeOf(IndexType type)
{
    switch (type) {
    case IndexType::eUnsignedByte:
        return sizeof(std::uint8_t);
    case IndexType::eUnsignedShort:
        return sizeof(std::uint16_t);
    case IndexType::eUnsignedInt:
        return sizeof(std::uint32_t);
    case IndexType::eInvalid:
        break;
    }
    std::unreachable();
}

template<typename T>
[[nodiscard]]
constexpr IndexType toIndexType();

template<>
[[nodiscard]]
constexpr IndexType toIndexType<std::uint8_t>() {
    return IndexType::eUnsignedByte;
}

template<>
[[nodiscard]]
constexpr IndexType toIndexType<std::uint16_t>() {
    return IndexType::eUnsignedShort;
}

template<>
[[nodiscard]]
constexpr IndexType toIndexType<std::uint32_t>() {
    return IndexType::eUnsignedInt;
}

} // namespace GraphicsCore::GPU
