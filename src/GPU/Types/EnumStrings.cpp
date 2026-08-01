#include "GraphicsCore/GPU/Types/Enums.h"
#include <utility>
#include <string_view>

namespace GraphicsCore::GPU {

[[nodiscard]]
std::string_view toString(ShaderStage stage) {
    switch (stage) {
    case GraphicsCore::GPU::ShaderStage::eVertex:
        return "Vertex Shader";
    case GraphicsCore::GPU::ShaderStage::eFragment:
        return "Fragment Shader";
    }
    std::unreachable();
}

} // namespace GraphicsCore::GPU