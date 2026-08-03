#pragma once
#include <cstddef>
#include <cstdint>
#include "GraphicsCore/GPU/Types/Enums.h"

namespace GraphicsCore::GPU {

class VertexAttribute
{
public:
    VertexAttribute(std::uint32_t location, std::uint32_t componentCount, std::size_t offset, VertexAttributeType type, bool bNormalized)
        : m_location(location)
        , m_componentCount(componentCount)
        , m_offset(offset)
        , m_type(type)
        , m_bNormalized(bNormalized) {}

    ~VertexAttribute() noexcept = default;
    VertexAttribute(const VertexAttribute& rhs) = default;
    VertexAttribute& operator=(const VertexAttribute& rhs) = default;
    VertexAttribute(VertexAttribute&& rhs) = default;
    VertexAttribute& operator=(VertexAttribute&& rhs) = default;

    [[nodiscard]]
    constexpr std::uint32_t location() const noexcept {
        return m_location;
    }

    [[nodiscard]]
    constexpr std::uint32_t componentCount() const noexcept {
        return m_componentCount;
    }

    [[nodiscard]]
    constexpr std::size_t offset() const noexcept {
        return m_offset;
    }

    [[nodiscard]]
    constexpr VertexAttributeType type() const noexcept {
        return m_type;
    }

    [[nodiscard]]
    constexpr bool normalized() const noexcept {
        return m_bNormalized;
    }

private:
    std::uint32_t m_location{};
    std::uint32_t m_componentCount{};
    std::size_t m_offset{};
    VertexAttributeType m_type{VertexAttributeType::eInvalid};
    bool m_bNormalized{};
};

} // namespace GraphicsCore::GPU
