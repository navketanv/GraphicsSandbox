#pragma once
#include "GraphicsCore/GPU/Types/Enums.h"
#include <OpenGL/gl.h>
namespace GraphicsCore::GPU {

[[nodiscard]]
GLenum toOpenGL(ShaderStage stage);

} // namespace GraphicsCore::GPU