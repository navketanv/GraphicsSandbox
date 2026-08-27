#pragma once

namespace GraphicsCore::Math {

class Vec4 {
public:
    constexpr Vec4() noexcept = default;

    constexpr Vec4(const Vec4&) noexcept = default;
    constexpr Vec4& operator=(const Vec4&) noexcept = default;

    constexpr Vec4(Vec4&&) noexcept = default;
    constexpr Vec4& operator=(Vec4&&) noexcept = default;

    ~Vec4() noexcept = default;

    constexpr Vec4(float x, float y, float z, float w) noexcept
        : m_x{x}, m_y{y}, m_z{z}, m_w{w} {}

    [[nodiscard]]
    constexpr float x() const noexcept { return m_x; }
    [[nodiscard]]
    constexpr float y() const noexcept { return m_y; }
    [[nodiscard]]
    constexpr float z() const noexcept { return m_z; }
    [[nodiscard]]
    constexpr float w() const noexcept { return m_w; }

private:
    float m_x{};
    float m_y{};
    float m_z{};
    float m_w{};
};

} // GraphicsCore::Math