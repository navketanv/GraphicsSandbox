#pragma once
#include <cstddef>
#include <span>

namespace util {

template<typename T>
[[nodiscard]]
std::span<const std::byte> asBytes(std::span<const T> data) noexcept
{
    const std::byte* pDataAsByte = reinterpret_cast<const std::byte*>(data.data());
    const std::size_t byteCount = data.size_bytes();
    return std::span<const std::byte>(pDataAsByte, byteCount);
}

} // namespace Util