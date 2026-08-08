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

[[nodiscard]]
std::string_view toString(VertexAttributeType type)
{
    switch (type) {
    case VertexAttributeType::eFloat:
        return std::string_view("Float");
    case VertexAttributeType::eUnsignedInt:
        return std::string_view("Unsigned Int");
    case VertexAttributeType::eUnsignedByte:
        return std::string_view("Unsigned Byte");
    case VertexAttributeType::eInvalid:
        return std::string_view("Invalid Vertex Attribute Type");
    }
    std::unreachable();
}

[[nodiscard]]
std::string_view toString(PrimitiveTopology topology) {
    switch (topology) {
    case PrimitiveTopology::eTriangles:
        return std::string_view("Trianlges");
    case GraphicsCore::GPU::PrimitiveTopology::eInvalid:
        return std::string_view("Invalid Primitive Topology");
    }
    std::unreachable();
}

[[nodiscard]]
std::string_view toString(IndexType type)
{
    switch (type) {
    case IndexType::eUnsignedByte:
        return std::string_view("Unsigned Byte");
    case IndexType::eUnsignedShort:
        return std::string_view("Unsigned Short");
    case IndexType::eUnsignedInt:
        return std::string_view("Unsigned Int");
    case IndexType::eInvalid:
        return std::string_view("Invalid Index Type");
    }
    std::unreachable();
}

} // namespace GraphicsCore::GPU
