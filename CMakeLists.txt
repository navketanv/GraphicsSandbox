cmake_minimum_required(VERSION 4.3.3)

project(GraphicsSandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GraphicsSandbox src/GraphicsSandbox.cpp
    src/include/GraphicsCore/Application.h src/include/GraphicsCore/Application.cpp
    src/include/Constants.h
)

include(GNUInstallDirs)
install(TARGETS GraphicsSandbox
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

target_link_libraries(GraphicsSandbox PRIVATE SDL2::SDL2 OpenGL::GL)
target_sources(GraphicsSandbox PRIVATE)
