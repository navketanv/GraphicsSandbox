#pragma once
#include <memory>
#include <SDL.h>
#include <string_view>
#include "GraphicsCore/Enums.h"
#include "GraphicsCore/detail/GLContextAccess.h"

namespace GraphicsCore {

class Window;

class GLContext
{
public:
    GLContext(Window& window);
    ~GLContext() = default;

    GLContext(const GLContext& rhs) = delete;
    GLContext& operator=(const GLContext& rhs) = delete;

    GLContext(GLContext&& rhs) = delete;
    GLContext& operator=(GLContext&& rhs) = delete;

private:
    struct GLContextDeleter
    {
        void operator()(SDL_GLContext pGLContext) noexcept {
            if (pGLContext != nullptr) {
                SDL_GL_DeleteContext(pGLContext);
            }
        }
    };

    void setSwapInterval(SwapInterval swapInterval) const ;

private:
    static constexpr std::string_view channel = "GLContext";
    std::unique_ptr<void, GLContextDeleter> m_pGLContext{};
    friend SDL_GLContext GraphicsCore::detail::contextHandle(GLContext& context) noexcept;
};

} // namespace GraphicsCore
