#include "GraphicsCore/GLContext.h"
#include "GraphicsCore/Window.h"
#include "GraphicsCore/detail/WindowAccess.h"
#include "utilities/Logger.h"
#include <stdexcept>
#include <string>

namespace GraphicsCore {

GLContext::GLContext(Window& window)
    : m_pGLContext(SDL_GL_CreateContext(GraphicsCore::detail::windowHandle(window))) {
    util::Logger::location();
    if (!m_pGLContext) {
        throw std::runtime_error(std::string("GLContext Creation: ") + SDL_GetError());
    }
    util::Logger::logInfo(channel, "SDL GLContext Creation succeeded");
    setSwapInterval(SwapInterval::eVSync);
}

void GLContext::setSwapInterval(SwapInterval swapInterval) const {
    if (SDL_GL_SetSwapInterval(static_cast<int>(swapInterval)) != 0) {
        util::Logger::logWarning(channel, SDL_GetError());
    } else {
        util::Logger::logInfo(channel, "SDL GLContext updates synchronized with the vertical retrace");
    }
}

} // namespace GraphicsCore
