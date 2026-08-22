#pragma once
#include "GraphicsCore/Geometry/MeshData.h"
#include "GraphicsCore/Geometry/Types/Enums.h"
#include "GraphicsCore/Geometry/Triangle.h"
#include "GraphicsCore/Geometry/Rectangle.h"

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
        }
    std::unreachable();
    }
};
} // namespace GraphicsCore::Geometry