#include "GraphicsCore/detail/WindowAccess.h"
#include "GraphicsCore/Window.h"


namespace GraphicsCore {

namespace detail {

SDL_Window* windowHandle(Window& window) noexcept {
    return window.m_pWindow.get();
}

} // namespace detail

} // namespace GraphicsCore
