#pragma once
#include "GraphicsCore/GPU/Shader.h"
#include "GraphicsCore/GPU/Mesh.h"

namespace GraphicsCore {

class Scene
{
public:
    Scene();
    ~Scene() noexcept;

    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    Scene(Scene&&) = delete;
    Scene& operator=(Scene&&) = delete;

    void render() const;

private:
    GPU::Shader m_shader;
    GPU::Mesh m_mesh;
};

} // namespace GraphicsCore
