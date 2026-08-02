#pragma once

namespace GraphicsCore::GPU {

enum class ShaderStage {
    eInvalid = 0,
    eVertex,
    eFragment
};

enum class BufferTarget {
    eInvalid = 0,
    eVertex,
    eIndex,
    eUniform
};

enum class BufferUsage {
    eInvalid = 0,
    eStaticDraw,
    eDynamicDraw,
    eStreamDraw
};

} //namespace GraphicsCore::GPU