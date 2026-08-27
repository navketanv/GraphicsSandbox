#include <gtest/gtest.h>
#include "GraphicsCore/Math/Vec4.h"
#include "GraphicsCore/Math/Mat4.h"

using GraphicsCore::Math::Mat4;
using GraphicsCore::Math::Vec4;

namespace GraphicsCore::Math::Tests {

constexpr bool identityVectorMultiplicationIsCorrect()
{
    constexpr Vec4 vector{1.0f, 2.0f, 3.0f, 4.0f};
    constexpr Vec4 result = Mat4::identity() * vector;
    return ((result.x() == 1.0f) && (result.y() == 2.0f) && (result.z() == 3.0f) && (result.w() == 4.0f));
}

static_assert(identityVectorMultiplicationIsCorrect());

TEST(Vec4Test, IdentityMatrixVectorMultiplicationCompileTime)
{
    static_assert(identityVectorMultiplicationIsCorrect());
}

TEST(Vec4Test, IdentityMatrixVectorMultiplication)
{
    const Vec4 vector{1.0f, 2.0f, 3.0f, 4.0f};
    const Vec4 result = Mat4::identity() * vector;
    EXPECT_FLOAT_EQ(result.x(), 1.0f);
    EXPECT_FLOAT_EQ(result.y(), 2.0f);
    EXPECT_FLOAT_EQ(result.z(), 3.0f);
    EXPECT_FLOAT_EQ(result.w(), 4.0f);
}

constexpr bool matrixVectorMultiplicationIsCorrect()
{
    constexpr Vec4 vector{1.0f, 1.0f, 1.0f, 1.0f};
    Mat4 matrix{};
    for (std::size_t row = 0; row < Mat4::dimension; ++row) {
        for (std::size_t col = 0; col < Mat4::dimension; ++col) {
            matrix(row, col) = static_cast<float>(row * Mat4::dimension + col + 1);
        }
    }
    const Vec4 result = matrix * vector;
    return ((result.x() == 10.0f) && (result.y() == 26.0f) && (result.z() == 42.0f) && (result.w() == 58.0f));
}

static_assert(matrixVectorMultiplicationIsCorrect());

TEST(Vec4Test, MatrixVectorMultiplicationCompileTime)
{
    static_assert(matrixVectorMultiplicationIsCorrect());
}

TEST(Vec4Test, MatrixVectorMultiplication)
{
    const Vec4 vector{1.0f, 1.0f, 1.0f, 1.0f};
    Mat4 matrix{};
    for (std::size_t row = 0; row < Mat4::dimension; ++row) {
        for (std::size_t col = 0; col < Mat4::dimension; ++col) {
            matrix(row, col) = static_cast<float>(row * Mat4::dimension + col + 1);
        }
    }
    const Vec4 result = matrix * vector;
    EXPECT_FLOAT_EQ(result.x(), 10.0f);
    EXPECT_FLOAT_EQ(result.y(), 26.0f);
    EXPECT_FLOAT_EQ(result.z(), 42.0f);
    EXPECT_FLOAT_EQ(result.w(), 58.0f);
}

constexpr bool zeroMatrixVectorMultiplicationIsCorrect()
{
    constexpr Mat4 matrix{};
    constexpr Vec4 vector{1.0f, 1.0f, 1.0f, 1.0f};

    constexpr Vec4 result = matrix * vector;
    return ((result.x() == 0.0f) && (result.y() == 0.0f) && (result.z() == 0.0f) && (result.w() == 0.0f));
}

static_assert(zeroMatrixVectorMultiplicationIsCorrect());

TEST(Vec4Test, ZeroMatrixVectorMultiplicationCompileTime)
{
    static_assert(zeroMatrixVectorMultiplicationIsCorrect());
}

TEST(Vec4Test, ZeroMatrixVectorMultiplication)
{
    const Mat4 matrix{};
    const Vec4 vector{1.0f, 2.0f, 3.0f, 1.0f};

    const Vec4 result = matrix * vector;

    EXPECT_FLOAT_EQ(result.x(), 0.0f);
    EXPECT_FLOAT_EQ(result.y(), 0.0f);
    EXPECT_FLOAT_EQ(result.z(), 0.0f);
    EXPECT_FLOAT_EQ(result.w(), 0.0f);
}

} // namespace GraphicsCore::Math
