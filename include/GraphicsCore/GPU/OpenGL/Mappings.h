#pragma once
#include "GraphicsCore/GPU/Types/Enums.h"
#include <OpenGL/gl3.h>

namespace GraphicsCore::GPU {

[[nodiscard]]
GLenum toOpenGL(ShaderStage stage);

[[nodiscard]]
GLenum toOpenGL(BufferTarget target);

[[nodiscard]]
GLenum toOpenGL(BufferUsage usage);

[[nodiscard]]
GLenum toOpenGL(VertexAttributeType type);

} // namespace GraphicsCore::GPUÏ