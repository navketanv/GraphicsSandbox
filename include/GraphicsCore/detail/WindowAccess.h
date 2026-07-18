#pragma once
#include <SDL.h>

namespace GraphicsCore {

class Window;

namespace detail {

SDL_Window* windowHandle(Window& window) noexcept;

} // namespace detail

} // namespace GraphicsCore
