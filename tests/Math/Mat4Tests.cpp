#include "GraphicsCore/Math/Mat4.h"
#include <cassert>

using GraphicsCore::Math::Mat4;

int main()
{
    constexpr Mat4 identity = Mat4::identity();
    constexpr Mat4 result = identity * identity;

    static_assert(result(0, 0) == 1.0f);
    static_assert(result(1, 1) == 1.0f);
    static_assert(result(2, 2) == 1.0f);
    static_assert(result(3, 3) == 1.0f);
    return 0;
}