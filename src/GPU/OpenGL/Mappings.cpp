#include "GraphicsCore/GPU/OpenGL/Mappings.h"
#include <utility>

namespace GraphicsCore::GPU {

[[nodiscard]]
GLenum toOpenGL(ShaderStage stage)
{
    switch(stage) {
    case GraphicsCore::GPU::ShaderStage::eVertex:
        return GL_VERTEX_SHADER;
    case GraphicsCore::GPU::ShaderStage::eFragment:
        return GL_FRAGMENT_SHADER;
    }
    std::unreachable();
}

} // namespace GraphicsCore::GPU