#pragma once
#include "GraphicsCore/GPU/Shader.h"
#include "GraphicsCore/GPU/Mesh.h"
#include "GraphicsCore/Geometry/Types/Enums.h"

namespace GraphicsCore {

class Scene
{
public:
    explicit Scene(GPU::Mesh mesh);
    ~Scene() noexcept;

    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    Scene(Scene&&) = delete;
    Scene& operator=(Scene&&) = delete;

    void setGeometry(Geometry::GeometryType type);

    void render() const;

private:
    GPU::Shader m_shader;
    GPU::Mesh m_mesh;
};

} // namespace GraphicsCore
