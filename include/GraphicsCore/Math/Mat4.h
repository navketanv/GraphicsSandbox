#pragma once
#include <cstddef>
#include <utility>

namespace GraphicsCore::Math {

class Mat4
{
public:
    static inline constexpr std::size_t dimension{4};
    constexpr Mat4() noexcept = default;

    constexpr Mat4(const Mat4&) noexcept = default;
    constexpr Mat4& operator=(const Mat4&) noexcept = default;

    constexpr Mat4(Mat4&&) noexcept = default;
    constexpr Mat4& operator=(Mat4&&) noexcept = default;

    ~Mat4() noexcept = default;

    [[nodiscard]]
    static constexpr Mat4 identity() noexcept {
        Mat4 mat4{};
        for (std::size_t index = 0; index < dimension; ++index) {
            mat4.m_data[index][index] = 1.0f;
        }
        return mat4;
    }

    constexpr float& operator()(std::size_t row, std::size_t column) noexcept {
        if ((row < dimension) && (column < dimension)) {
            return m_data[row][column];
        }
        std::unreachable();
    }

    constexpr float operator()(std::size_t row, std::size_t column) const noexcept {
        if ((row < dimension) && (column < dimension)) {
            return m_data[row][column];
        }
        std::unreachable();
    }

    [[nodiscard]]
    constexpr float* data() noexcept {
        return &m_data[0][0];
    }

    [[nodiscard]]
    constexpr const float* data() const noexcept {
        return &m_data[0][0];
    }

private:
    float m_data[dimension][dimension]{};
};

[[nodiscard]]
constexpr Mat4 operator*(const Mat4& lhs, const Mat4& rhs) noexcept {
    Mat4 result{};
    for (std::size_t row = 0; row < Mat4::dimension; ++row) {
        for (std::size_t col = 0; col < Mat4::dimension; ++col) {
            for (std::size_t index = 0; index < Mat4::dimension; ++index) {
                result(row, col) += lhs(row, index) * rhs(index, col);
            }
        }
    }
    return result;
}

} // namespace GraphicsCore::Math
