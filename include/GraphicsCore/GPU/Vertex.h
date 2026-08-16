#pragma once
#include <array>

namespace GraphicsCore::GPU {

struct Vertex {
    std::array<float, 3> m_position;
    std::array<float, 3> m_color;
};

} // namespace GraphicsCore::GPU
