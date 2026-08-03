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

} // namespace GraphicsCore::GPU
