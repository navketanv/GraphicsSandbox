#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include "GraphicsCore/Geometry/MeshData.h"
#include "GraphicsCore/Geometry/Vertex.h"

namespace GraphicsCore::Geometry {

class Triangle
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
    static constexpr std::array<Vertex, 3> vertices {
        Vertex {
            {0.0f, 0.5f, 0.0f},
            {1.0f, 0.0f, 0.0f}
        },
        Vertex {
            {-0.5f, -0.5f, 0.0f},
            {0.0f, 1.0f, 0.0f}
        },
        Vertex {
            {0.5f, -0.5f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    };
    static constexpr std::array<std::uint32_t, 3> indices {
        0, 1, 2
    };
};

} // namespace GraphicsCore::Geometry