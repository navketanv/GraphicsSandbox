#pragma once

namespace GraphicsCore {

class Color
{
public:
    constexpr Color(float red, float green, float blue, float alpha = 1.0f) noexcept
        : m_red(red)
        , m_green(green)
        , m_blue(blue)
        , m_alpha(alpha)
    {}

    [[nodiscard]] float red() const noexcept { return m_red; }
    [[nodiscard]] float green() const noexcept { return m_green; }
    [[nodiscard]] float blue() const noexcept { return m_blue; }
    [[nodiscard]] float alpha() const noexcept { return m_alpha; }

private:
    float m_red{};
    float m_green{};
    float m_blue{};
    float m_alpha{1.0f};
};

} // namespace GraphicsCore

namespace GraphicsCore::Colors {

inline constexpr Color Red{1.0f, 0.0f, 0.0f, 1.0f};
inline constexpr Color Green{0.0f, 1.0f, 0.0f, 1.0f};
inline constexpr Color Blue{0.0f, 0.0f, 1.0f, 1.0f};
inline constexpr Color Black{0.0f, 0.0f, 0.0f, 1.0f};
inline constexpr Color White{1.0f, 1.0f, 1.0f, 1.0f};
inline constexpr Color Transparent {0.f, 0.f, 0.f, 0.f};

} // namespace GraphicsCore::Colors
