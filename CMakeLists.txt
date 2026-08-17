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

    # ==========================================================
    # Application
    # ==========================================================

    src/GraphicsSandbox.cpp
    src/Application.cpp
    src/Scene.cpp


    # ==========================================================
    # Core / Platform
    # ==========================================================

    src/SDLSystem.cpp
    src/Window.cpp
    src/WindowAccess.cpp
    src/GLContext.cpp
    src/GLContextAccess.cpp
    src/Renderer.cpp


    # ==========================================================
    # Utilities
    # ==========================================================

    src/Logger.cpp
    src/FileSystem.cpp


    # ==========================================================
    # Geometry
    # ==========================================================

    src/TriangleGeometry.cpp


    # ==========================================================
    # GPU
    # ==========================================================

    src/GPU/Shader.cpp
    src/GPU/Buffer.cpp
    src/GPU/VertexArray.cpp
    src/GPU/Mesh.cpp


    # ==========================================================
    # GPU / OpenGL
    # ==========================================================

    src/GPU/OpenGL/Mappings.cpp


    # ==========================================================
    # GPU / Types
    # ==========================================================

    src/GPU/Types/EnumStrings.cpp


    # ==========================================================
    # Public Headers
    # ==========================================================

    include/Constants.h

    include/GraphicsCore/Application.h
    include/GraphicsCore/Scene.h

    include/GraphicsCore/SDLSystem.h
    include/GraphicsCore/Window.h
    include/GraphicsCore/Renderer.h
    include/GraphicsCore/GLContext.h

    include/GraphicsCore/Color.h
    include/GraphicsCore/Enums.h

    include/GraphicsCore/detail/GLContextAccess.h
    include/GraphicsCore/detail/WindowAccess.h


    # ==========================================================
    # Utilities / Headers
    # ==========================================================

    include/Utilities/Logger.h
    include/Utilities/FileSystem.h
    include/Utilities/BitwiseOperations.h
    include/Utilities/ScopeGuard.h


    # ==========================================================
    # GPU / Headers
    # ==========================================================

    include/GraphicsCore/GPU/Shader.h
    include/GraphicsCore/GPU/Buffer.h
    include/GraphicsCore/GPU/VertexArray.h
    include/GraphicsCore/GPU/VertexAttribute.h
    include/GraphicsCore/GPU/VertexLayout.h
    include/GraphicsCore/GPU/Mesh.h
    include/GraphicsCore/GPU/Vertex.h


    # ==========================================================
    # GPU / Types
    # ==========================================================

    include/GraphicsCore/GPU/Types/GraphicsTypes.h
    include/GraphicsCore/GPU/Types/Enums.h
    include/GraphicsCore/GPU/Types/EnumStrings.h


    # ==========================================================
    # GPU / OpenGL
    # ==========================================================

    include/GraphicsCore/GPU/OpenGL/Mappings.h


    # ==========================================================
    # GPU / Utilities
    # ==========================================================

    include/GraphicsCore/GPU/Utilities/EnumUtilities.h
    include/GraphicsCore/GPU/Utilities/ScopedBinder.h


    # ==========================================================
    # Geometry
    # ==========================================================

    include/Geometry/TriangleGeometry.h
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

add_custom_command(TARGET GraphicsSandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:GraphicsSandbox>/assets"
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
