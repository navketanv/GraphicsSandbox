#define GL_SILENCE_DEPRECATION
#include "GraphicsCore/GPU/Mesh.h"
#include "Utilities/Logger.h"
#include "GraphicsCore/GPU/Utilities/ScopedBinder.h"
#include "GraphicsCore/GPU/OpenGL/Mappings.h"
#include "GraphicsCore/GPU/Types/EnumStrings.h"
#include <OpenGL/gl3.h>
#include <sstream>
#include <exception>

namespace GraphicsCore::GPU {

Mesh::Mesh(const Geometry::MeshData& meshData)
    : m_indexType(meshData.indexType)
{
    util::Logger::location();

    if (m_indexType == GPU::IndexType::eInvalid) {
        std::stringstream ss;
        ss << "m_indexType = " << toString(m_indexType) << '\n';
        util::Logger::logException(channel, ss.str());
        std::terminate();
    }

    if (meshData.indices.empty()) {
        std::stringstream ss;
        ss << "meshData.indices.size() = " << meshData.indices.size() << '\n';
        util::Logger::logException(channel, ss.str());
        std::terminate();
    }

    const std::size_t indexSize = sizeOf(m_indexType);
    if (meshData.indices.size() % indexSize != 0) {
        std::stringstream ss;
        ss << "Index Buffer Size (" << meshData.indices.size()
           << "), is not a multiple of index element size ("
           << indexSize << ")\n";
        util::Logger::logException(channel, ss.str());
        std::terminate();
    }

    m_indexCount = meshData.indices.size() / indexSize;
    m_vertexBuffer.upload(meshData.vertices, BufferUsage::eStaticDraw);
    m_indexBuffer.upload(meshData.indices, BufferUsage::eStaticDraw);

    m_vertexArray.attachVertexBuffer(m_vertexBuffer, meshData.layout);
    m_vertexArray.attachIndexBuffer(m_indexBuffer);
}

Mesh::~Mesh() noexcept {
    util::Logger::location();
}

void Mesh::draw() const noexcept {
    if (m_indexCount == 0) {
        std::stringstream ss;
        ss << "m_indexCount = " <<  m_indexCount << '\n';
        util::Logger::logInfo(channel, ss.str());
        return;
    }
    ScopedBinder<VertexArray> vao(m_vertexArray);
    glDrawElements(toOpenGL(m_topology), static_cast<GLsizei>(m_indexCount), toOpenGL(m_indexType), nullptr);
}

} // namespace GraphicsCore::GPU
