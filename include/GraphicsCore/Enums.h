#pragma once
#include <cstdint>

namespace GraphicsCore {

enum class BufferBit : uint32_t
{
    eColor   = 1u << 0,
    eDepth   = 1u << 1,
    eStencil = 1u << 2
};

enum class SwapInterval {
    eImmediate = 0,
    eVSync = 1,
    eAdaptive = -1
};

} // namespace GraphicsCore