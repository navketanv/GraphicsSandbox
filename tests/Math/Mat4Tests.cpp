#include <gtest/gtest.h>
#include "GraphicsCore/Math/Mat4.h"

using GraphicsCore::Math::Mat4;

namespace GraphicsCore::Math::Tests {

constexpr bool identityMatrixMultiplicationIsCorrect()
{
    constexpr Mat4 identity = Mat4::identity();
    constexpr Mat4 result = identity * identity;
    return (result(0, 0) == 1.0f) && (result(1, 1) == 1.0f) && (result(2, 2) == 1.0f) && (result(3, 3) == 1.0f);
}

static_assert(identityMatrixMultiplicationIsCorrect());

TEST(Mat4Test, IdentityMatrixMultiplicationCompileTime)
{
    static_assert(identityMatrixMultiplicationIsCorrect());
}

TEST(Mat4Test, IdentityMatrixMultiplication)
{
    const Mat4 identity = Mat4::identity();
    const Mat4 result = identity * identity;

    EXPECT_FLOAT_EQ(result(0, 0), 1.0f);
    EXPECT_FLOAT_EQ(result(1, 1), 1.0f);
    EXPECT_FLOAT_EQ(result(2, 2), 1.0f);
    EXPECT_FLOAT_EQ(result(3, 3), 1.0f);
}

} // GraphicsCore::Math::Tests
