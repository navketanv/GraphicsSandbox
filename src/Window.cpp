#include "GraphicsCore/Window.h"
#include "utilities/Logger.h"
#include "Constants.h"
#include <stdexcept>
#include <string>
namespace GraphicsCore {

Window::Window()
    : m_pWindow(SDL_CreateWindow(Constants::gProjectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 Constants::gWIDTH, Constants::gHEIGHT, SDL_WINDOW_OPENGL)) {
    util::Logger::location();
    if (!m_pWindow) {
        throw std::runtime_error(std::string("Window Creation: ") + SDL_GetError());
    }
    util::Logger::logInfo(channel, "SDL windowCreation succeeded");
    raise();
}

void Window::raise() const noexcept {
    SDL_RaiseWindow(m_pWindow.get());
}

} // namespace GraphicsCore
