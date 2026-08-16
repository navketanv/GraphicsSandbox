#include "GraphicsCore/SDLSystem.h"
#include "Utilities/Logger.h"
#include <SDL.h>
#include <stdexcept>
#include <string>
#include <sstream>

namespace GraphicsCore
{

SDLSystem::SDLSystem() {
    util::Logger::location();
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error(std::string("SDLSystem Init: ") + SDL_GetError());
    }

    auto setAttribute = [](SDL_GLattr attr, int value) {
        if (SDL_GL_SetAttribute(attr, value) != 0) {
            std::stringstream ss;
            ss << SDL_GetError() << '\n';
            util::Logger::logException(channel, ss.str());
            throw std::runtime_error(ss.str());
        }
    };
    setAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    setAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    setAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    util::Logger::logInfo(channel, "SDL initialization succeeded");
}

SDLSystem::~SDLSystem() {
    util::Logger::location();
    util::Logger::logInfo(channel, "Clean up all initialized subsystems");
    SDL_Quit();
}

} // namespace GraphicsCore
