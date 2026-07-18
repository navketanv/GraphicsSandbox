#pragma once
#include <memory>
#include <string_view>
#include "GraphicsCore/SDLSystem.h"
#include "GraphicsCore/Window.h"
#include "GraphicsCore/GLContext.h"
#include "GraphicsCore/Renderer.h"

namespace GraphicsCore
{

class Application
{
public:
    Application();
    ~Application();

    Application(const Application& rhs) = delete;
    Application& operator=(const Application& rhs) = delete;

    Application(Application&& rhs) = delete;
    Application& operator=(Application&& rhs) = delete;

    int run();

private:
    static constexpr std::string_view channel = "Application";
    bool m_bIsRunning{true};
    std::unique_ptr<SDLSystem> m_pSDLSystem{};
    std::unique_ptr<Window> m_pWindow{};
    std::unique_ptr<GLContext> m_pContext{};
    std::unique_ptr<Renderer> m_pRenderer{};
};

} // namespace GraphicsCore
