#define GL_SILENCE_DEPRECATION
#include "GraphicsCore/GPU/Mesh.h"
#include "Utilities/Logger.h"
#include "GraphicsCore/GPU/Utilities/ScopedBinder.h"
#include "GraphicsCore/GPU/OpenGL/Mappings.h"
#include <OpenGL/gl3.h>
#include <sstream>

namespace GraphicsCore::GPU {

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
