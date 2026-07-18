#include "GraphicsCore/detail/GLContextAccess.h"
#include "GraphicsCore/GLContext.h"

namespace GraphicsCore {

class GLContext;

namespace detail {

SDL_GLContext contextHandle(GLContext& context) noexcept {
    return context.m_pGLContext.get();
}

}  // namespace detail

} // namespace GraphicsCore
