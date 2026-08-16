#include "Geometry/TriangleGeometry.h"
#include "GraphicsCore/GPU/Types/Enums.h"
#include "GraphicsCore/GPU/Utilities/EnumUtilities.h"

namespace GraphicsCore {

GPU::VertexLayout TriangleGeometry::vertexLayout()
{
    GPU::VertexLayout layout{};
    const std::size_t positionOffset = 0;
    const std::size_t colorOffset = positionComponentCount() * GPU::sizeOf(GPU::VertexAttributeType::eFloat);
    layout.addAttribute(0, positionComponentCount(), positionOffset, GPU::VertexAttributeType::eFloat, false);
    layout.addAttribute(1, colorComponentCount(), colorOffset, GPU::VertexAttributeType::eFloat, false);
    return layout;
}

} // namespace GraphicsCore