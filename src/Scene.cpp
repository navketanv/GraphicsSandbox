#include "GraphicsCore/Scene.h"
#include "GraphicsCore/GPU/Utilities/ScopedBinder.h"
#include "Utilities/FileSystem.h"
#include "Utilities/Logger.h"
#include "GraphicsCore/Geometry/Triangle.h"

namespace GraphicsCore {

Scene::Scene()
    : m_shader(
        util::FileSystem::readTextFile("assets/shaders/triangle.vert.glsl"),
        util::FileSystem::readTextFile("assets/shaders/triangle.frag.glsl")
    )
    , m_mesh(Geometry::Triangle::create())
{
    util::Logger::location();
}

void Scene::render() const
{
    GPU::ScopedBinder<GPU::Shader> shaderBinder(m_shader);
    m_mesh.draw();
}

Scene::~Scene() noexcept
{
    util::Logger::location();
}

} // namespace GraphicsCore

