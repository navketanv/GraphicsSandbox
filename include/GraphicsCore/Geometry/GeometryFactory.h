#pragma once
#include "GraphicsCore/Geometry/MeshData.h"
#include "GraphicsCore/Geometry/Types/Enums.h"
#include "GraphicsCore/Geometry/Triangle.h"
#include "GraphicsCore/Geometry/Rectangle.h"
#include "GraphicsCore/Geometry/Cube.h"

namespace GraphicsCore::Geometry {

class GeometryFactory {
public:
    [[nodiscard]]
    static MeshData createGeometry(GeometryType type) {
        switch (type) {
        case GeometryType::eTriangle:
            return Triangle::create();
        case GeometryType::eRectangle:
            return Rectangle::create();
        case GeometryType::eCube:
            return Cube::create();
        }
    std::unreachable();
    }
};
} // namespace GraphicsCore::Geometry