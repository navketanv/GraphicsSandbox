#pragma once
#include <array>

namespace GraphicsCore::Geometry {

struct Vertex {
    std::array<float, 3> m_position;
    std::array<float, 3> m_color;
};

} // namespace GraphicsCore::Geometry
