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

enum class VertexAttributeType {
    eInvalid = 0,
    eFloat,
    eUnsignedInt,
    eUnsignedByte
};

enum class PrimitiveTopology {
    eInvalid = 0,
    eTriangles
};

enum class IndexType {
    eInvalid = 0,
    eUnsignedByte,
    eUnsignedShort,
    eUnsignedInt
};

} //namespace GraphicsCore::GPU