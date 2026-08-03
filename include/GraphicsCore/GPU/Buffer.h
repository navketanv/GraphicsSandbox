#pragma once
#include "GraphicsCore/GPU/Types/GraphicsTypes.h"
#include "GraphicsCore/GPU/Types/Enums.h"
#include <string_view>
#include <span>

namespace GraphicsCore::GPU {

class Buffer
{
public:
    explicit Buffer(BufferTarget target);
    ~Buffer() noexcept;

    Buffer(const Buffer& rhs) = delete;
    Buffer& operator=(const Buffer& rhs) = delete;

    Buffer(Buffer&& rhs) noexcept;
    Buffer& operator=(Buffer&& rhs) noexcept;

    void upload(std::span<const std::byte> data, BufferUsage usage);

    void bind() const noexcept;
    void unbind() const noexcept;

    [[nodiscard]]
    constexpr BufferTarget target() const noexcept {
        return m_target;
    }

private:    
    void destroyBuffer() noexcept;
    void logUpload(std::size_t size, BufferUsage usage) const;

private:
    static inline constexpr std::string_view channel = "Buffer";
    BufferTarget m_target{};
    detail::GraphicsHandle m_bufferHandle{};
};

} // namespace GraphicsCore::GPU
