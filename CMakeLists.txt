cmake_minimum_required(VERSION 4.3.3)

project(GraphicsSandbox LANGUAGES CXX)

# ==========================================================
# Project Options
# ==========================================================

option(
    ENABLE_ASAN
    "Enable Address Sanitizer"
    ON
)

option(
    ENABLE_UBSAN
    "Enable Undefined Behaviour Sanitizer"
    OFF
)

option(
    ENABLE_WARNINGS_AS_ERRORS
    "Treat Compiler Warnings As Errors"
    OFF
)

# ==========================================================
# Build Configuration
# ==========================================================

include(cmake/CompilerWarnings.cmake)
include(cmake/CompilerOptions.cmake)
include(cmake/Sanitizers.cmake)

# ==========================================================
# Dependencies
# ==========================================================

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

# ==========================================================
# Target
# ==========================================================

add_executable(GraphicsSandbox
    src/GraphicsSandbox.cpp
    src/Logger.cpp
    src/Application.cpp
    src/SDLSystem.cpp
    src/GLContext.cpp
    src/GLContextAccess.cpp
    src/Renderer.cpp
    src/Window.cpp
    src/WindowAccess.cpp

    include/Constants.h
    include/utilities/Logger.h
    include/GraphicsCore/Application.h
    include/GraphicsCore/SDLSystem.h
    include/GraphicsCore/GLContext.h
    include/GraphicsCore/detail/GLContextAccess.h
    include/GraphicsCore/Window.h
    include/GraphicsCore/detail/WindowAccess.h
    include/GraphicsCore/Renderer.h
    include/GraphicsCore/Color.h
    include/utilities/BitwiseOperations.h
    include/GraphicsCore/Enums.h
)

target_include_directories(GraphicsSandbox
    PRIVATE
        include
)

target_link_libraries(GraphicsSandbox
    PRIVATE
        SDL2::SDL2
        OpenGL::GL
)

# ==========================================================
# enable public interfaces
# ==========================================================

enable_warnings(GraphicsSandbox)
enable_project_options(GraphicsSandbox)
enable_sanitizers(GraphicsSandbox)

include(GNUInstallDirs)

install(TARGETS GraphicsSandbox
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
