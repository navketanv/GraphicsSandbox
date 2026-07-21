#pragma once
#include <SDL.h>
#include <memory>
#include <string_view>
#include "GraphicsCore/detail/WindowAccess.h"

namespace GraphicsCore {

class Window
{
public:
    Window();
    ~Window();

    Window(const Window& rhs) = delete;
    Window& operator=(const Window& rhs) = delete;

    Window(Window&& rhs) = delete;
    Window& operator=(Window&& rhs) = delete;

private:
    struct WindowDeleter
    {
        void operator()(SDL_Window* pWindow) const noexcept {
            if (pWindow != nullptr) {
                SDL_DestroyWindow(pWindow);
            }
        }
    };

    void raise() const noexcept;

private:
    static constexpr std::string_view channel = "Window";
    std::unique_ptr<SDL_Window, WindowDeleter> m_pWindow{};
    friend SDL_Window* GraphicsCore::detail::windowHandle(Window& window) noexcept;
};

} // namespace GraphicsCore
