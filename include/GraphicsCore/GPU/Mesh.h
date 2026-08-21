#pragma once
#include <string_view>
#include "GraphicsCore/GPU/Types/Enums.h"
#include "GraphicsCore/Geometry/MeshData.h"
#include "GraphicsCore/GPU/VertexArray.h"
#include "GraphicsCore/GPU/Buffer.h"

namespace GraphicsCore::GPU {

class Mesh
{
public:
    Mesh(const Geometry::MeshData& meshData);
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

} // namespace GraphicsCore::GPU
