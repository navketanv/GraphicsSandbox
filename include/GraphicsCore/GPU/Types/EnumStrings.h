#pragma once
#include "GraphicsCore/GPU/Types/Enums.h"
#include <string_view>

namespace GraphicsCore::GPU {

[[nodiscard]]
std::string_view toString(ShaderStage stage);

[[nodiscard]]
std::string_view toString(BufferTarget target);

[[nodiscard]]
std::string_view toString(BufferUsage usage);

[[nodiscard]]
std::string_view toString(VertexAttributeType type);

[[nodiscard]]
std::string_view toString(PrimitiveTopology topology);

[[nodiscard]]
std::string_view toString(IndexType type);

} // namespace GraphicsCore::GPU
