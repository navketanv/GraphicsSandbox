#include "GraphicsCore/Renderer.h"

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>

#include "GraphicsCore/detail/WindowAccess.h"
#include "utilities/BitwiseOperations.h"
#include "utilities/Logger.h"

namespace GraphicsCore {

Renderer::Renderer(Window& window)
    : m_window(window)
{
    util::Logger::location();
    util::Logger::logInfo(channel, "Renderer created");
}

Renderer::~Renderer() {
    util::Logger::location();
    util::Logger::logInfo(channel, "Renderer destroyed");
}

void Renderer::beginFrame() const noexcept {
    clearBuffers();
}

void Renderer::endFrame() const noexcept {
    SDL_GL_SwapWindow(detail::windowHandle(m_window));
}

void Renderer::setClearColor(const Color& color) const noexcept {
    glClearColor(color.red(), color.green(), color.blue(), color.alpha());
}

void Renderer::setClearColor(float red, float green, float blue, float alpha) const noexcept {
    glClearColor(red, green, blue, alpha);
}

void Renderer::clearBuffers() const noexcept {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Renderer::clear(BufferBit bits) const noexcept {
    glClear(static_cast<GLbitfield>(toGLBufferBits(bits)));
}

uint32_t Renderer::toGLBufferBits(BufferBit bits) noexcept {
    uint32_t mask{};

    if (hasFlag(bits, BufferBit::eColor)) {
        mask |= GL_COLOR_BUFFER_BIT;
    }

    if (hasFlag(bits, BufferBit::eDepth)) {
        mask |= GL_DEPTH_BUFFER_BIT;
    }

    if (hasFlag(bits, BufferBit::eStencil)) {
        mask |= GL_STENCIL_BUFFER_BIT;
    }

    return mask;
}

} // namespace GraphicsCore