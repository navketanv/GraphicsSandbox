#pragma once
#include <string_view>

namespace GraphicsCore
{

class SDLSystem
{
public:
    SDLSystem();
    ~SDLSystem();

private:
    static constexpr std::string_view channel = "SDLSystem";
};

} // namespace GraphicsCore
