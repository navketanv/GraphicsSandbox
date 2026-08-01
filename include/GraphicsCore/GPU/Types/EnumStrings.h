#pragma once
#include "GraphicsCore/GPU/Types/Enums.h"
#include <string_view>

namespace GraphicsCore::GPU {

[[nodiscard]]
std::string_view toString(ShaderStage stage);

} // namespace GraphicsCore::GPU