#define GL_SILENCE_DEPRECATION
#include "GraphicsCore/Application.h"
#include "Constants.h"
#include <iostream>
#include <cstdio>
#include <SDL.h>
#include <OpenGL/gl.h>

Application::Application() {
    printLocation();
}

Application::~Application() {
    printLocation();
}

void Application::run() {
    printLocation();
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << SDL_GetError() << '\n';
        return;
    }

    SDL_Window* pWindow = SDL_CreateWindow(Constants::gProjectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            Constants::gWIDTH, Constants::gHEIGHT, SDL_WINDOW_OPENGL);
    if (!pWindow) {
        std::cerr << SDL_GetError() << '\n';
        SDL_Quit();
        return;
    }

    SDL_RaiseWindow(pWindow);
    SDL_GLContext pContext = SDL_GL_CreateContext(pWindow);
    if (!pContext) {
        std::cerr << SDL_GetError() << '\n';
        SDL_DestroyWindow(pWindow);
        SDL_Quit();
        return;
    }

    if (SDL_GL_SetSwapInterval(1) != 0) {
        std::cerr << "VSync Unavailable: " << SDL_GetError() << '\n';
    }

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
            break;
        }
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(pWindow);
    }
    if (pContext) {
        SDL_GL_DeleteContext(pContext);
    }

    if (pWindow) {
        SDL_DestroyWindow(pWindow);
    }
    SDL_Quit();
}

void Application::printLocation(const std::source_location& location) {
    puts(location.function_name());
}