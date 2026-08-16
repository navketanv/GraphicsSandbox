#include "Utilities/FileSystem.h"
#include <fstream>
#include <stdexcept>

namespace util {

std::string FileSystem::readTextFile(std::string_view fileName) {
    std::string resultString{};
    std::ifstream inputFileStream((std::string(fileName)));
    if (inputFileStream.is_open()) {
        std::string line{};
        while (std::getline(inputFileStream, line)) {
            resultString += (line + '\n');
        }
    } else {
        const std::string message =  "Failed To Open File: " + std::string(fileName) + '\n';
        throw std::runtime_error(message);
    }
    return resultString;
}

} // namespace util
