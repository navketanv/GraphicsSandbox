#pragma once
#include <cstddef>
#include <vector>
#include "GraphicsCore/Geometry/VertexLayout.h"
#include "GraphicsCore/GPU/Types/Enums.h"

namespace GraphicsCore::Geometry {

struct MeshData
{
    std::vector<std::byte> vertices;
    std::vector<std::byte> indices;
    VertexLayout layout;
    GPU::IndexType indexType;
};

} // namespace GraphicsCore::Geometry

