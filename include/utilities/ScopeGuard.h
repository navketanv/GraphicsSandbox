#pragma once
#include <concepts>
#include <utility>

namespace util {

template<std::invocable Cleanup>
class ScopeGuard {
public:
    template<std::invocable F>
        requires(std::constructible_from<Cleanup, std::decay_t<F>>)
    explicit ScopeGuard(F&& cleanup)
        : m_cleanup(std::forward<F>(cleanup)) {}

    ~ScopeGuard() noexcept {
        m_cleanup();
    }

    ScopeGuard(const ScopeGuard<Cleanup>&) = delete;
    ScopeGuard<Cleanup>& operator=(const ScopeGuard<Cleanup>&) = delete;
    ScopeGuard(ScopeGuard<Cleanup>&&) = delete;
    ScopeGuard<Cleanup>& operator=(ScopeGuard<Cleanup>&&) = delete;

private:
    Cleanup m_cleanup;
};

template<typename T>
ScopeGuard(T&&) -> ScopeGuard<std::remove_cvref_t<T>>;

} // namespace util
