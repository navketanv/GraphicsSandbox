#pragma once
#include "GraphicsCore/GPU/Types/GraphicsTypes.h"
#include "GraphicsCore/GPU/Buffer.h"
#include "GraphicsCore/Geometry/VertexLayout.h"
#include <string_view>

namespace GraphicsCore::GPU {

class VertexArray
{
public:
    VertexArray();
    ~VertexArray() noexcept;

    VertexArray(const VertexArray& rhs) = delete;
    VertexArray& operator=(const VertexArray& rhs) = delete;

    VertexArray(VertexArray&& rhs) noexcept;
    VertexArray& operator=(VertexArray&& rhs) noexcept;

    void attachVertexBuffer(const Buffer& buffer, const Geometry::VertexLayout& layout) const;
    void attachIndexBuffer(const Buffer& buffer) const;

    void bind() const noexcept;
    void unbind() const noexcept;

private:
    void destroyVertexArray() noexcept;

private:
    static inline constexpr std::string_view channel = "VertexArray";
    detail::GraphicsHandle m_vertexArrayHandle{};
};

} // namespace GraphicsCore::GPU
