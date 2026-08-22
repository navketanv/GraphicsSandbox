#include "GraphicsCore/Scene.h"
#include "GraphicsCore/GPU/Utilities/ScopedBinder.h"
#include "GraphicsCore/Geometry/GeometryFactory.h"
#include "Utilities/FileSystem.h"
#include "Utilities/Logger.h"

namespace GraphicsCore {

Scene::Scene(GPU::Mesh mesh)
    : m_shader(
        util::FileSystem::readTextFile("assets/shaders/basic.vert.glsl"),
        util::FileSystem::readTextFile("assets/shaders/basic.frag.glsl")
    )
    , m_mesh(std::move(mesh))
{
    util::Logger::location();
}

void Scene::setGeometry(Geometry::GeometryType type)
{
    const Geometry::MeshData meshData = Geometry::GeometryFactory::createGeometry(type);
    m_mesh = GPU::Mesh(meshData);
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

