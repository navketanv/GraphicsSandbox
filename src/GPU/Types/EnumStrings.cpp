#include "GraphicsCore/GPU/Types/EnumStrings.h"
#include <utility>

namespace GraphicsCore::GPU {

[[nodiscard]]
std::string_view toString(ShaderStage stage) {
    switch (stage) {
    case ShaderStage::eVertex:
        return std::string_view("Vertex Shader");
    case ShaderStage::eFragment:
        return std::string_view("Fragment Shader");
    case ShaderStage::eInvalid:
        return std::string_view("Invalid Shader Stage");
    }
    std::unreachable();
}

[[nodiscard]]
std::string_view toString(BufferTarget target)
{
    switch (target) {
    case BufferTarget::eVertex:
        return std::string_view("Vertex Buffer");
    case BufferTarget::eIndex:
        return std::string_view("Index Buffer");
    case BufferTarget::eUniform:
        return std::string_view("Uniform Buffer");
    case BufferTarget::eInvalid:
        return std::string_view("Invalid Buffer Target");
    }
    std::unreachable();
}

[[nodiscard]]
std::string_view toString(BufferUsage usage)
{
    switch (usage) {
    case BufferUsage::eStaticDraw:
        return std::string_view("Static Draw");
    case BufferUsage::eDynamicDraw:
        return std::string_view("Dynamic Draw");
    case BufferUsage::eStreamDraw:
        return std::string_view("Stream Draw");
    case BufferUsage::eInvalid:
        return std::string_view("Invalid Buffer Usage");
    }
    std::unreachable();
}

} // namespace GraphicsCore::GPU
