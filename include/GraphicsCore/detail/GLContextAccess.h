#pragma once
#include <SDL.h>

namespace GraphicsCore {

class GLContext;

namespace detail {

SDL_GLContext contextHandle(GLContext& context) noexcept;

}  // namespace detail

} // namespace GraphicsCore
