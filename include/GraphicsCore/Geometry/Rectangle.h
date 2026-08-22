#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include "GraphicsCore/Geometry/Vertex.h"
#include "GraphicsCore/Geometry/MeshData.h"

namespace GraphicsCore::Geometry {

class Rectangle
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
    static constexpr std::array<Vertex, 4> vertices {
        Vertex {
            {-0.5f, 0.5f, 0.0f},
            {1.0f, 0.0f, 0.0f}
        },
        Vertex {
            {0.5f, 0.5f, 0.0f},
            {0.0f, 1.0f, 0.0f}
        },
        Vertex {
            {-0.5f, -0.5f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        },
        Vertex {
            {0.5f, -0.5f, 0.0f},
            {1.0f, 0.0f, 0.0f}
        }
    };
    static constexpr std::array<std::uint32_t, 6> indices {
        0, 1, 2, 2, 1, 3
    };
};

} // namespace GraphicsCore::Geometry
