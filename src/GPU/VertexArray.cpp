#define GL_SILENCE_DEPRECATION
#include "GraphicsCore/GPU/VertexArray.h"
#include "GraphicsCore/GPU/OpenGL/Mappings.h"
#include "GraphicsCore/GPU/Types/EnumStrings.h"
#include "GraphicsCore/GPU/Utilities/ScopedBinder.h"
#include "utilities/Logger.h"
#include <OpenGL/gl3.h>
#include <sstream>

namespace GraphicsCore::GPU {

VertexArray::VertexArray()
{
    util::Logger::location();
    GLuint vaoId{};
    glGenVertexArrays(1, &vaoId);
    if (vaoId == 0) {
        std::stringstream ss;
        ss << "OpenGL Returned Invalid VAO ID\n";
        util::Logger::logException(channel, ss.str());
        throw std::runtime_error(ss.str());
    }
    m_vertexArrayHandle = static_cast<detail::GraphicsHandle>(vaoId);
    std::stringstream ss;
    ss << "VAO Handle Created with id = " << m_vertexArrayHandle << '\n';
    util::Logger::logInfo(channel, ss.str());
}

VertexArray::~VertexArray() noexcept
{
    if (m_vertexArrayHandle != 0) {
        util::Logger::location();
        std::stringstream ss;
        ss << "VAO Handle Being Deleted with id = " << m_vertexArrayHandle << '\n';
        util::Logger::logInfo(channel, ss.str());
        destroyVertexArray();
    }
}

VertexArray::VertexArray(VertexArray&& rhs) noexcept
    : m_vertexArrayHandle(std::exchange(rhs.m_vertexArrayHandle, 0))
{
    util::Logger::location();
}

VertexArray& VertexArray::operator=(VertexArray&& rhs) noexcept
{
    util::Logger::location();
    if (this != &rhs) {
        destroyVertexArray();
        m_vertexArrayHandle = std::exchange(rhs.m_vertexArrayHandle, 0);
    }
    return *this;
}

void VertexArray::attachVertexBuffer(const Buffer& buffer, const VertexLayout& layout) const
{
    if (buffer.target() != BufferTarget::eVertex) {
        std::stringstream ss;
        ss << "Invalid Buffer Target = " << toString(buffer.target())
            << '\n'
           << "Attempting to attach a non-vertex buffer as a vertex buffer.\n";
        util::Logger::logException(channel, ss.str());
        throw std::runtime_error(ss.str());
    }

    for (const auto& attribute : layout.attributes()) {
        if ((attribute.componentCount() == 0) || (attribute.componentCount() > 4)) {
            std::stringstream ss;
            ss << "Invalid Component Count = " << attribute.componentCount() << '\n';
            util::Logger::logException(channel, ss.str());
            throw std::runtime_error(ss.str());
        }

        if (attribute.type() == VertexAttributeType::eInvalid) {
            std::stringstream ss;
            ss << "Invalid  VertexAttributeType = " <<  toString(attribute.type()) << '\n';
            util::Logger::logException(channel, ss.str());
            throw std::runtime_error(ss.str());
        }
    }

    ScopedBinder<VertexArray> vao(*this);
    ScopedBinder<Buffer> bufferObj(buffer);

    for (const auto& attribute : layout.attributes()) {
        glEnableVertexAttribArray(static_cast<GLuint>(attribute.location()));
        glVertexAttribPointer(
            static_cast<GLuint>(attribute.location()),
            static_cast<GLint>(attribute.componentCount()),
            toOpenGL(attribute.type()),
            attribute.normalized() ? GL_TRUE : GL_FALSE,
            static_cast<GLsizei>(layout.stride()),
            reinterpret_cast<const void*>(attribute.offset())
        );
    }
}

void VertexArray::attachIndexBuffer(const Buffer& buffer) const
{
    if (buffer.target() != BufferTarget::eIndex) {
        std::stringstream ss;
        ss << "Invalid Buffer Target = " << toString(buffer.target())
            << '\n'
           << "Attempting to attach a non-index buffer as an index buffer.\n";
        util::Logger::logException(channel, ss.str());
        throw std::runtime_error(ss.str());
    }
    ScopedBinder<VertexArray> vao(*this);
    ScopedBinder<Buffer> bufferObj(buffer);
}

void VertexArray::bind() const noexcept
{
    if (m_vertexArrayHandle != 0) {
        const GLuint vaoId = static_cast<GLuint>(m_vertexArrayHandle);
        glBindVertexArray(vaoId);
    }
}

void VertexArray::unbind() const noexcept {
    glBindVertexArray(0);
}

void VertexArray::destroyVertexArray() noexcept
{
    if (m_vertexArrayHandle != 0) {
        const GLuint vaoId = static_cast<GLuint>(m_vertexArrayHandle);
        glDeleteVertexArrays(1, &vaoId);
        m_vertexArrayHandle = 0;
    }
}

} // namespace GraphicsCore::GPU

