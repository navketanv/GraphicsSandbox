#pragma once
#include <string>
#include <string_view>

namespace util {

class FileSystem
{
public:
    [[nodiscard]]
    static std::string readTextFile(std::string_view fileName);
};

} // namespace util
