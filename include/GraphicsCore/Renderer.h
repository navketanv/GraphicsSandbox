#pragma once
#include <string_view>
#include "GraphicsCore/Color.h"
#include "GraphicsCore/Enums.h"

namespace GraphicsCore {

class Window;

class Renderer
{
public:
    Renderer(Window& window);
    ~Renderer();

    Renderer(const Renderer& rhs) = delete;
    Renderer& operator=(const Renderer& rhs) = delete;

    Renderer(Renderer&& rhs) = delete;
    Renderer& operator=(Renderer&& rhs) = delete;

    void beginFrame() const noexcept;
    void endFrame() const noexcept;

    void setClearColor(const Color& color) const noexcept;
    void setClearColor(float red, float green, float blue, float alpha) const noexcept;

    void clearBuffers() const noexcept;
    void clear(BufferBit bits) const noexcept;

private:
    static uint32_t toGLBufferBits(BufferBit bits) noexcept;

private:
    static constexpr std::string_view channel = "Renderer";
    Window& m_window;
};

} // namespace GraphicsCore
