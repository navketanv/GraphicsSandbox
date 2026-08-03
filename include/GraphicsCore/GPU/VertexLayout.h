#pragma once
#include <concepts>
#include <vector>
#include <span>
#include "GraphicsCore/GPU/VertexAttribute.h"
#include "GraphicsCore/GPU/Utilities/EnumUtilities.h"

namespace GraphicsCore::GPU {

class VertexLayout
{
public:
    VertexLayout() = default;
    ~VertexLayout() noexcept = default;
    VertexLayout(const VertexLayout& rhs) = default;
    VertexLayout& operator=(const VertexLayout& rhs) = default;
    VertexLayout(VertexLayout&& rhs) = default;
    VertexLayout& operator=(VertexLayout&& rhs) = default;

    template<typename... Args>
        requires(std::constructible_from<VertexAttribute, Args...>)
    void addAttribute(Args&&... args)
    {
        m_attributes.emplace_back(std::forward<Args>(args)...);
        const VertexAttribute& attribute = m_attributes.back();
        m_stride += attribute.componentCount() * sizeOf(attribute.type());
    }

    [[nodiscard]]
    constexpr std::size_t stride() const noexcept {
        return m_stride;
    }

    [[nodiscard]]
    constexpr std::span<const VertexAttribute> attributes() const noexcept {
        return m_attributes;
    }

    void clear() noexcept {
        m_attributes.clear();
        m_stride = 0;
    }

private:
    std::vector<VertexAttribute> m_attributes{};
    std::size_t m_stride{};
};

} // namespace GraphicsCore::GPU
