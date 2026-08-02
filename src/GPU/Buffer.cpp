#define GL_SILENCE_DEPRECATION
#include "GraphicsCore/GPU/Buffer.h"
#include "GraphicsCore/GPU/OpenGL/Mappings.h"
#include "GraphicsCore/GPU/Types/EnumStrings.h"
#include "utilities/Logger.h"
#include <OpenGL/gl3.h>
#include <sstream>
#include <utility>

namespace GraphicsCore::GPU {

Buffer::Buffer(BufferTarget target)
    : m_target(target)
{
    util::Logger::location();
    if (m_target == BufferTarget::eInvalid) {
        std::stringstream ss;
        ss << "Invalid Buffer Target = " << toString(m_target) << '\n';
        util::Logger::logException(channel, ss.str());
        throw std::runtime_error(ss.str());
    }

    GLuint bufferId{};
    glGenBuffers(1, &bufferId);
    if (bufferId == 0) {
        std::stringstream ss;
        ss << "OpenGL Returned Invalid Buffer Handle For Target = " << toString(m_target) << '\n';
        util::Logger::logException(channel, ss.str());
        throw std::runtime_error(ss.str());
    }

    m_bufferHandle = static_cast<detail::GraphicsHandle>(bufferId);
    std::stringstream ss;
    ss << "Buffer Handle Created with id = " << m_bufferHandle << ", Target = " << toString(m_target) << '\n';
    util::Logger::logInfo(channel, ss.str());
}

Buffer::~Buffer() noexcept
{
    if (m_bufferHandle != 0) {
        util::Logger::location();
        std::stringstream ss;
        ss << "Buffer Handle Being Deleted with id = " << m_bufferHandle << ", Target = " << toString(m_target) << '\n';
        util::Logger::logInfo(channel, ss.str());
        destroyBuffer();
    }
}

Buffer::Buffer(Buffer&& rhs) noexcept
    : m_target(std::exchange(rhs.m_target, BufferTarget::eInvalid))
    , m_bufferHandle(std::exchange(rhs.m_bufferHandle, 0))
{
    util::Logger::location();
}

Buffer& Buffer::operator=(Buffer&& rhs) noexcept
{
    util::Logger::location();
    if (this != &rhs) {
        destroyBuffer();
        m_target = std::exchange(rhs.m_target, BufferTarget::eInvalid);
        m_bufferHandle = std::exchange(rhs.m_bufferHandle, 0);
    }
    return *this;
}

void Buffer::upload(std::span<const std::byte> data, BufferUsage usage)
{
    if (m_bufferHandle == 0) {
        const std::string_view expMessage = "Cannot Upload Data To Invalid Buffer Handle.\n";
        util::Logger::logException(channel, expMessage);
        throw std::runtime_error(std::string(expMessage));
    }

    if (usage == BufferUsage::eInvalid) {
        const std::string_view expMessage = "Invalid Buffer Usage.\n";
        util::Logger::logException(channel, expMessage);
        throw std::runtime_error(std::string(expMessage));
    }

    bind();
    glBufferData(toOpenGL(m_target), static_cast<GLsizeiptr>(data.size()), data.data(), toOpenGL(usage));
    unbind();
    logUpload(data.size(), usage);
}

constexpr BufferTarget Buffer::target() const noexcept {
    return m_target;
}

void Buffer::bind() const noexcept {
    if (m_bufferHandle != 0) {
        const GLuint bufferId = static_cast<GLuint>(m_bufferHandle);
        glBindBuffer(toOpenGL(m_target), bufferId);
    }
}

void Buffer::unbind() const noexcept {
    glBindBuffer(toOpenGL(m_target), 0);
}

constexpr detail::GraphicsHandle Buffer::handle() const noexcept {
    return m_bufferHandle;
}

void Buffer::destroyBuffer() noexcept {
    if (m_bufferHandle != 0) {
        const GLuint bufferId = static_cast<GLuint>(m_bufferHandle);
        glDeleteBuffers(1, &bufferId);
        m_bufferHandle = 0;
    }
}

void Buffer::logUpload(std::size_t size, BufferUsage usage) const {
    if (size == 0) {
        std::stringstream ss;
        ss << "Uploading Empty Data To The Buffer.\n"
           << "Handle = " << m_bufferHandle
           << ", Target = " << toString(m_target)
           << ", Usage = " << toString(usage)
           << '\n';
        util::Logger::logWarning(channel, ss.str());
    } else {
        std::stringstream ss;
        ss << "Buffer Uploaded :\n"
           << "Handle = " << m_bufferHandle
           << ", Target = " << toString(m_target)
           << ", Usage = " << toString(usage)
           << ", Size (#bytes) = " << size
           << '\n';
        util::Logger::logInfo(channel, ss.str());
    }
}

} // namespace GraphicsCore::GPU

