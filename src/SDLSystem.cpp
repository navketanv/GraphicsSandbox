#include "GraphicsCore/SDLSystem.h"
#include "utilities/Logger.h"
#include <SDL.h>
#include <stdexcept>
#include <string>


namespace GraphicsCore
{

SDLSystem::SDLSystem() {
    util::Logger::location();
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error(std::string("SDLSystem Init: ") + SDL_GetError());
    }
    util::Logger::logInfo(channel, "SDL initialization succeeded");
}

SDLSystem::~SDLSystem() {
    util::Logger::location();
    util::Logger::logInfo(channel, "Clean up all initialized subsystems");
    SDL_Quit();
}

} // namespace GraphicsCore
