#pragma once

namespace GraphicsCore::Math {

class Vec3 {
public:
    constexpr Vec3() noexcept = default;

    constexpr Vec3(const Vec3&) noexcept = default;
    constexpr Vec3& operator=(const Vec3&) noexcept = default;

    constexpr Vec3(Vec3&&) noexcept = default;
    constexpr Vec3& operator=(Vec3&&) noexcept = default;

    ~Vec3() noexcept = default;

    constexpr Vec3(float x, float y, float z) noexcept
        : m_x{x}, m_y{y}, m_z{z} {}

    [[nodiscard]]
    constexpr float x() const noexcept { return m_x; }
    [[nodiscard]]
    constexpr float y() const noexcept { return m_y; }
    [[nodiscard]]
    constexpr float z() const noexcept { return m_z; }

private:
    float m_x{};
    float m_y{};
    float m_z{};
};

} // namespace GraphicsCore::Math
