#pragma once
#include <string_view>
#include "GraphicsCore/GPU/Types/Enums.h"
#include "GraphicsCore/GPU/VertexLayout.h"
#include "GraphicsCore/GPU/VertexArray.h"
#include "GraphicsCore/GPU/Buffer.h"
#include "Utilities/Logger.h"

namespace GraphicsCore::GPU {

template<typename T>
concept IndexElementType =
    std::same_as<T, std::uint8_t> || std::same_as<T, std::uint16_t> || std::same_as<T, std::uint32_t>;

class Mesh
{
public:
    template<typename VertexT, IndexElementType IndexT>
        requires(std::is_trivially_copyable_v<VertexT>)
    Mesh(std::span<const VertexT> vertices, std::span<const IndexT> indices, const VertexLayout& layout);
    ~Mesh() noexcept;

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    Mesh(Mesh&&) = default;
    Mesh& operator=(Mesh&&) = default;

    void draw() const noexcept;

private:
    static inline constexpr std::string_view channel = "Mesh";
    VertexArray m_vertexArray{};
    Buffer m_vertexBuffer{BufferTarget::eVertex};
    Buffer m_indexBuffer{BufferTarget::eIndex};
    PrimitiveTopology m_topology{PrimitiveTopology::eTriangles};
    IndexType m_indexType{IndexType::eInvalid};
    std::size_t m_indexCount{};
};

template<typename VertexT, IndexElementType IndexT>
    requires(std::is_trivially_copyable_v<VertexT>)
Mesh::Mesh(std::span<const VertexT> vertices, std::span<const IndexT> indices, const VertexLayout& layout)
    : m_indexType(toIndexType<IndexT>())
    , m_indexCount(indices.size())
{
    util::Logger::location();
    m_vertexBuffer.upload(std::as_bytes(vertices), BufferUsage::eStaticDraw);
    m_indexBuffer.upload(std::as_bytes(indices), BufferUsage::eStaticDraw);

    m_vertexArray.attachVertexBuffer(m_vertexBuffer, layout);
    m_vertexArray.attachIndexBuffer(m_indexBuffer);
}

} // namespace GraphicsCore::GPU
