#pragma once
#include <cstddef>
#include <string_view>
#include "GraphicsCore/GPU/Types/GraphicsTypes.h"
#include "GraphicsCore/GPU/Types/Enums.h"
#include <initializer_list>

namespace GraphicsCore::GPU {

class Shader
{
public:
    Shader(std::string_view vertexSource, std::string_view fragmentSource);
    ~Shader() noexcept;

    Shader(const Shader& rhs) = delete;
    Shader& operator=(const Shader& rhs) = delete;

    Shader(Shader&& rhs) noexcept;
    Shader& operator=(Shader&& rhs) noexcept;

    constexpr detail::GraphicsHandle handle() const noexcept;

private:
    void bind() const noexcept;
    void unbind() const noexcept;

    static void verifyShaderCompilation(GraphicsCore::GPU::ShaderStage shaderStage, GraphicsCore::detail::GraphicsHandle shaderHandle);
    static detail::GraphicsHandle compileShader(GraphicsCore::GPU::ShaderStage shaderStage, std::string_view source);
    static void verifyProgramLink(GraphicsCore::detail::GraphicsHandle programHandle);
    static detail::GraphicsHandle createProgram(detail::GraphicsHandle vertexShaderHandle, detail::GraphicsHandle fragmentShaderHandle);
    static void destroyShaders(std::initializer_list<GraphicsCore::detail::GraphicsHandle> shaders, GraphicsCore::detail::GraphicsHandle programHandle);
    void destroyProgram() noexcept;

private:
    static inline constexpr std::string_view channel = "Shader";
    detail::GraphicsHandle m_programHandle{};
};

} // namespace GraphicsCore::GPU
