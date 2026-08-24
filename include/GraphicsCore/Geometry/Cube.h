#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include "GraphicsCore/Geometry/Vertex.h"
#include "GraphicsCore/Geometry/MeshData.h"

namespace GraphicsCore::Geometry {

class Cube
{
public:
    [[nodiscard]]
    static MeshData create();

private:
    static constexpr std::size_t positionComponentCount() noexcept {
        return static_cast<std::size_t>(Vertex{}.m_position.size());
    }

    static constexpr std::size_t colorComponentCount() noexcept {
        return static_cast<std::size_t>(Vertex{}.m_color.size());
    }

private:
    static constexpr std::array<std::array<float, 3>, 8> v = {{
        {-0.5f, 0.5f, 0.5f}, {0.5f, 0.5f, 0.5f}, {-0.5f, -0.5f, 0.5f}, {0.5f, -0.5f, 0.5f},
        {-0.5f, 0.5f, -0.5f}, {0.5f, 0.5f, -0.5f}, {-0.5f, -0.5f, -0.5f}, {0.5f, -0.5f, -0.5f}
    }};

    static constexpr std::array<std::array<float, 3>, 8> c = {{
        {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f},
        {1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f}
    }};

    static constexpr std::array<Vertex, 8> vertices = {
        Vertex {v[0], c[0]},
        Vertex {v[1], c[1]},
        Vertex {v[2], c[2]},
        Vertex {v[3], c[3]},
        Vertex {v[4], c[4]},
        Vertex {v[5], c[5]},
        Vertex {v[6], c[6]},
        Vertex {v[7], c[7]}
    };

    static constexpr std::array<std::uint32_t, 36> indices{
        // Front
        0,  1,  2,
        2,  1,  3,

        // Back
        4,  6,  5,
        6,  7,  5,

        // Left
        4,  0, 6,
        6,  0, 2,

        // Right
        5, 7, 1,
        7, 3, 1,

        // Top
        4, 5, 0,
        0, 5, 1,

        // Bottom
        2, 6, 3,
        6, 7, 3
    };
};

} // namespace GraphicsCore::Geometry
