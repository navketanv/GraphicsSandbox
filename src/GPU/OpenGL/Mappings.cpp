#include "GraphicsCore/GPU/OpenGL/Mappings.h"
#include <utility>

namespace GraphicsCore::GPU {

[[nodiscard]]
GLenum toOpenGL(ShaderStage stage)
{
    switch(stage) {
    case ShaderStage::eVertex:
        return GL_VERTEX_SHADER;
    case ShaderStage::eFragment:
        return GL_FRAGMENT_SHADER;
    case ShaderStage::eInvalid:
        break;
    }
    std::unreachable();
}

[[nodiscard]]
GLenum toOpenGL(BufferTarget target)
{
    switch (target) {
    case BufferTarget::eVertex:
        return GL_ARRAY_BUFFER;
    case BufferTarget::eIndex:
        return GL_ELEMENT_ARRAY_BUFFER;
    case BufferTarget::eUniform:
        return GL_UNIFORM_BUFFER;
    case BufferTarget::eInvalid:
        break;
    }
    std::unreachable();
}

[[nodiscard]]
GLenum toOpenGL(BufferUsage usage)
{
    switch (usage) {
    case BufferUsage::eStaticDraw:
        return GL_STATIC_DRAW;
    case BufferUsage::eDynamicDraw:
        return GL_DYNAMIC_DRAW;
    case BufferUsage::eStreamDraw:
        return GL_STREAM_DRAW;
    case BufferUsage::eInvalid:
        break;
    }
    std::unreachable();
}

[[nodiscard]]
GLenum toOpenGL(VertexAttributeType type)
{
    switch (type) {
    case VertexAttributeType::eFloat:
        return GL_FLOAT;
    case VertexAttributeType::eUnsignedInt:
        return GL_UNSIGNED_INT;
    case VertexAttributeType::eUnsignedByte:
        return GL_UNSIGNED_BYTE;
    case VertexAttributeType::eInvalid:
        break;
    }
    std::unreachable();
}

[[nodiscard]]
GLenum toOpenGL(PrimitiveTopology topology)
{
    switch (topology) {
    case PrimitiveTopology::eTriangles:
        return GL_TRIANGLES;
    case PrimitiveTopology::eInvalid:
        break;
    }
    std::unreachable();
}

[[nodiscard]]
GLenum toOpenGL(IndexType type) {
    switch (type) {
    case IndexType::eUnsignedByte:
        return GL_UNSIGNED_BYTE;
    case IndexType::eUnsignedShort:
        return GL_UNSIGNED_SHORT;
    case IndexType::eUnsignedInt:
        return GL_UNSIGNED_INT;
    case IndexType::eInvalid:
        break;
    }
    std::unreachable();
}

} // namespace GraphicsCore::GPU
