#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include "GraphicsCore/GPU/Vertex.h"
#include "GraphicsCore/GPU/VertexLayout.h"

namespace GraphicsCore {

struct TriangleGeometry {
    static constexpr std::array<GPU::Vertex, 3> vertices {
        GPU::Vertex {
            {0.0f, 0.5f, 0.0f},
            {1.0f, 0.0f, 0.0f}
        },
        GPU::Vertex {
            {-0.5f, -0.5f, 0.0f},
            {0.0f, 1.0f, 0.0f}
        },
        GPU::Vertex {
            {0.5f, -0.5f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    };
    static constexpr std::array<std::uint32_t, 3> indices {
        0, 1, 2
    };

    static constexpr auto positionComponentCount() noexcept {
        return static_cast<std::size_t>(GPU::Vertex{}.m_position.size());
    }

    static constexpr auto colorComponentCount() noexcept {
        return static_cast<std::size_t>(GPU::Vertex{}.m_color.size());
    }

    [[nodiscard]]
    static GPU::VertexLayout vertexLayout();
};

} // namespace GraphicsCore