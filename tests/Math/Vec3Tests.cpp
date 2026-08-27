#include <gtest/gtest.h>
#include "GraphicsCore/Math/Vec3.h"

using GraphicsCore::Math::Vec3;

namespace GraphicsCore::Math::Tests {

TEST(Vec3Test, ConstructionCompileTime)
{
    constexpr Vec3 vector{1.0f, 2.0f, 3.0f};
    static_assert(vector.x() == 1.0f);
    static_assert(vector.y() == 2.0f);
    static_assert(vector.z() == 3.0f);
}

TEST(Vec3Test, Construction)
{
    const Vec3 vector{1.0f, 2.0f, 3.0f};
    EXPECT_FLOAT_EQ(vector.x(), 1.0f);
    EXPECT_FLOAT_EQ(vector.y(), 2.0f);
    EXPECT_FLOAT_EQ(vector.z(), 3.0f);
}

} // namespace GraphicsCore::Math::Tests