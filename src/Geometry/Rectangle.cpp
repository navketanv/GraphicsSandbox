#include "GraphicsCore/Geometry/Rectangle.h"
#include "Utilities/ByteViews.h"

namespace GraphicsCore::Geometry {

MeshData Rectangle::create()
{
    MeshData meshData{};
    meshData.vertices.assign_range(util::asBytes<const Vertex>(vertices));
    meshData.indices.assign_range(util::asBytes<const std::uint32_t>(indices));
    meshData.layout.addAttribute(0, positionComponentCount(), offsetof(Vertex, m_position), GPU::VertexAttributeType::eFloat, false);
    meshData.layout.addAttribute(1, colorComponentCount(), offsetof(Vertex, m_color), GPU::VertexAttributeType::eFloat, false);
    meshData.indexType = GPU::IndexType::eUnsignedInt;
    return meshData;
}

} // namespace GraphicsCore::Geometry