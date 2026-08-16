#include "GraphicsCore/Scene.h"
#include "GraphicsCore/GPU/Utilities/ScopedBinder.h"
#include "Utilities/FileSystem.h"
#include "Utilities/Logger.h"
#include "Geometry/TriangleGeometry.h"
#include <span>

namespace GraphicsCore {

Scene::Scene()
    : m_shader(
        util::FileSystem::readTextFile("assets/shaders/triangle.vert.glsl"),
        util::FileSystem::readTextFile("assets/shaders/triangle.frag.glsl")
    )
    , m_mesh(std::span<const GPU::Vertex>{TriangleGeometry::vertices}, std::span<const std::uint32_t>{TriangleGeometry::indices}, TriangleGeometry::vertexLayout())
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

