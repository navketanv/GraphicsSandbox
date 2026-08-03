#pragma once

namespace GraphicsCore::GPU {
template<typename T>
concept Bindable = requires(const T& obj)
{
    { obj.bind() } noexcept;
    { obj.unbind() } noexcept;
};

template<Bindable T>
class [[nodiscard]] ScopedBinder {
public:
    explicit ScopedBinder(const T& obj)
        : m_obj(obj)
    {
        m_obj.bind();
    }

    ~ScopedBinder() noexcept
    {
        m_obj.unbind();
    }

    ScopedBinder(const ScopedBinder<T>&) = delete;
    ScopedBinder<T>& operator=(const ScopedBinder<T>&) = delete;
    ScopedBinder(ScopedBinder<T>&&) = delete;
    ScopedBinder<T>& operator=(ScopedBinder<T>&&) = delete;

private:
    const T& m_obj;
};

} // namespace GraphicsCore::GPU