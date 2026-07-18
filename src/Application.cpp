#define GL_SILENCE_DEPRECATION
#include "GraphicsCore/Application.h"
#include "GraphicsCore/Color.h"
#include "utilities/Logger.h"
#include <SDL.h>
#include <OpenGL/gl.h>

namespace GraphicsCore
{

Application::Application()
    : m_pSDLSystem{std::make_unique<SDLSystem>()}
    , m_pWindow{std::make_unique<Window>()}
{
    util::Logger::location();
    m_pContext = std::make_unique<GLContext>(*m_pWindow);
    m_pRenderer = std::make_unique<Renderer>(*m_pWindow);
    util::Logger::logInfo(channel, "Application Created");
}

Application::~Application() {
    util::Logger::location();
    util::Logger::logInfo(channel, "Application Destroyed");
}

int Application::run() {
    util::Logger::logInfo(channel, "Application Run Started");
    while (m_bIsRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                m_bIsRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    m_bIsRunning = false;
                }
                break;
            default:
                break;
            }
        }
        if (!m_bIsRunning) {
            util::Logger::logInfo(channel, "Application Run Stopped");
            break;
        }
        m_pRenderer->beginFrame();
        m_pRenderer->setClearColor(Colors::Red);
        m_pRenderer->endFrame();
    }
    return 0;
}

} // namespace GraphicsCore
