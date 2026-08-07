#define GL_SILENCE_DEPRECATION
#include "GraphicsCore/GPU/Shader.h"
#include "GraphicsCore/GPU/Types/EnumStrings.h"
#include "GraphicsCore/GPU/OpenGL/Mappings.h"
#include "Utilities/Logger.h"
#include "Utilities/ScopeGuard.h"
#include <OpenGL/gl3.h>
#include <string>
#include <sstream>

namespace GraphicsCore::GPU {

Shader::Shader(std::string_view vertexSource, std::string_view fragmentSource) {
    util::Logger::location();
    detail::GraphicsHandle vertexShaderHandle = compileShader(ShaderStage::eVertex, vertexSource);
    const GLuint vertexShaderId = static_cast<GLuint>(vertexShaderHandle);
    detail::GraphicsHandle fragmentShaderHandle{};
    try {
        fragmentShaderHandle = compileShader(ShaderStage::eFragment, fragmentSource);
    } catch (...) {
        glDeleteShader(vertexShaderId);
        util::Logger::logException(channel, "Fragment Shader Creation Failed. Vertex Shader Cleaned-Up\n");
        throw;
    }

    m_programHandle = createProgram(vertexShaderHandle, fragmentShaderHandle);
    std::stringstream ss;
    ss << "program created with id = " << m_programHandle << '\n';
    util::Logger::logInfo(channel, ss.str());
}

Shader::~Shader() noexcept {
    util::Logger::location();
    if (m_programHandle != 0) {
        std::stringstream ss;
        ss << "program being deleted with id = " << m_programHandle << '\n';
        util::Logger::logInfo(channel, ss.str());
    }
    destroyProgram();
}

Shader::Shader(Shader&& rhs) noexcept
    : m_programHandle(std::exchange(rhs.m_programHandle, 0))
{
    util::Logger::location();
}

Shader& Shader::operator=(Shader&& rhs) noexcept {
    util::Logger::location();
    if (this != &rhs) {
        destroyProgram();
        m_programHandle = std::exchange(rhs.m_programHandle, 0);
    }
    return *this;
}

void Shader::bind() const noexcept {
    if (m_programHandle != 0) {
        const GLuint programId = static_cast<GLuint>(m_programHandle);
        glUseProgram(programId);
    }
}

void Shader::unbind() const noexcept {
    glUseProgram(0);
}

constexpr detail::GraphicsHandle Shader::handle() const noexcept {
    return m_programHandle;
}

void Shader::verifyShaderCompilation(GraphicsCore::GPU::ShaderStage shaderStage, GraphicsCore::detail::GraphicsHandle shaderHandle)
{
    util::Logger::location();
    GLint compileStatus{};
    const GLuint shaderId = static_cast<GLuint>(shaderHandle);
    const std::string_view shaderName = toString(shaderStage);
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_TRUE) {
        return;
    }
    GLint logLength{};
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);
    std::string log;
    if (logLength > 0) {
        log.resize(static_cast<std::size_t>(logLength));
        glGetShaderInfoLog(shaderId, logLength, nullptr, log.data());
    }
    const std::string message =  std::string(shaderName) + std::string(", Compilation Failed:\n") + log;
    util::Logger::logError(channel, message);
    glDeleteShader(shaderId);
    throw std::runtime_error(message);
}

detail::GraphicsHandle Shader::compileShader(GraphicsCore::GPU::ShaderStage shaderStage, std::string_view source)
{
    util::Logger::location();
    if (shaderStage == ShaderStage::eInvalid) {
        const std::string_view expMessage = std::string_view("Invalid Shader Stage.\n");
        util::Logger::logException(channel, expMessage);
        throw std::runtime_error(std::string(expMessage));
    }

    const GLenum shaderType = toOpenGL(shaderStage);
    const std::string_view shaderName = toString(shaderStage);
    const GLuint shaderId = glCreateShader(shaderType);
    if (shaderId == 0) {
        const std::string expMessage = std::string(shaderName) + std::string(", Creation Failed.\n");
        util::Logger::logException(channel, expMessage);
        throw std::runtime_error(expMessage);
    }
    const GLchar* shaderSource = source.data();
    const GLint length = static_cast<GLint>(source.size());
    glShaderSource(shaderId, 1, &shaderSource, &length);
    glCompileShader(shaderId);
    const detail::GraphicsHandle shaderHandle = static_cast<detail::GraphicsHandle>(shaderId);
    verifyShaderCompilation(shaderStage, shaderHandle);
    return shaderHandle;
}

void Shader::verifyProgramLink(GraphicsCore::detail::GraphicsHandle programHandle)
{
    util::Logger::location();
    GLint linkStatus{};
    const GLuint programId = static_cast<GLuint>(programHandle);
    glGetProgramiv(programId, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == GL_TRUE) {
        return;
    }
    GLint logLength{};
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);
    std::string log;
    if (logLength > 0) {
        log.resize(static_cast<std::size_t>(logLength));
        glGetProgramInfoLog(programId, logLength, nullptr, log.data());
    }
    const std::string message = std::string("Program Linking Failed:\n") + log;
    util::Logger::logException(channel, message);
    throw std::runtime_error(message);
}

detail::GraphicsHandle Shader::createProgram(detail::GraphicsHandle vertexShaderHandle, detail::GraphicsHandle fragmentShaderHandle)
{
    util::Logger::location();
    const GLuint programId = glCreateProgram();
    if (programId == 0) {
        const std::string_view message = "Program Creation failed, returned zero\n";
        util::Logger::logException(channel, message);
        throw std::runtime_error(std::string(message));
    }

    const GLuint vertexShaderId = static_cast<GLuint>(vertexShaderHandle);
    const GLuint fragmentShaderId = static_cast<GLuint>(fragmentShaderHandle);
    const detail::GraphicsHandle programHandle = static_cast<detail::GraphicsHandle>(programId);

    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);

    bool bVerifiedProgramLink{false};
    util::ScopeGuard shaderCleanup([&]() noexcept {
        destroyShaders(std::initializer_list<detail::GraphicsHandle>{vertexShaderHandle, fragmentShaderHandle}, programHandle);
        if (!bVerifiedProgramLink) {
            glDeleteProgram(programId);
        }
    });

    verifyProgramLink(programHandle);
    bVerifiedProgramLink = true;

    return programHandle;
}

void Shader::destroyShaders(std::initializer_list<GraphicsCore::detail::GraphicsHandle> shaders, detail::GraphicsHandle programHandle)
{
    const GLuint programId = static_cast<GLuint>(programHandle);
    for (const auto& shader : shaders) {
        const GLuint shaderId = static_cast<GLuint>(shader);
        glDetachShader(programId, shaderId);
    }
    for (const auto& shader : shaders) {
        const GLuint shaderId = static_cast<GLuint>(shader);
        glDeleteShader(shaderId);
    }
}

void Shader::destroyProgram() noexcept {
    if (m_programHandle != 0) {
        const GLuint programId = static_cast<GLuint>(m_programHandle);
        glDeleteProgram(programId);
        m_programHandle = 0;
    }
}

} // namespace GraphicsCore::GPU
