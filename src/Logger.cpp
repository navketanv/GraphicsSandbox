#include "utilities/Logger.h"
#include <cstdio>
#include <sstream>

namespace util {

void Logger::logDebug(std::string_view channelName, std::string_view message) {
    log(LogLevel::eDebug, channelName, message);
}

void Logger::logError(std::string_view channelName, std::string_view message) {
    log(LogLevel::eError, channelName, message);
}

void Logger::logException(std::string_view channelName, std::string_view message) {
    log(LogLevel::eException, channelName, message);
}

void Logger::logInfo(std::string_view channelName, std::string_view message) {
    log(LogLevel::eInfo, channelName, message);
}

void Logger::logVerbose(std::string_view channelName, std::string_view message) {
    log(LogLevel::eVerbose, channelName, message);
}

void Logger::logWarning(std::string_view channelName, std::string_view message) {
    log(LogLevel::eWarning, channelName, message);
}

void Logger::location(const std::source_location& location) {
    std::puts(formatLocation(location).c_str());
}

void Logger::detailedLocation(const std::source_location& location) {
    std::puts(formatLocation(location, true).c_str());
}

constexpr std::string_view Logger::enumToString(LogLevel level) noexcept {
    switch (level) {
    case LogLevel::eDebug:
        return "[DEBUG]";
    case LogLevel::eError:
        return "[ERROR]";
    case LogLevel::eException:
        return "[EXCEPTION]";
    case LogLevel::eInfo:
        return "[INFO]";
    case LogLevel::eVerbose:
        return "[VERBOSE]";
    case LogLevel::eWarning:
        return "[WARNING]";
    default:
        return "[INFO]";
    }
}

std::string Logger::formatLog(LogLevel level, std::string_view channel, std::string_view message) {
    std::stringstream ss;
    ss << std::string(enumToString(level))
       << " ["
       << channel
       << "] "
       << message
       << '\n';
    return ss.str();
}

std::string Logger::formatLocation(const std::source_location& location, bool bDetailedLocation) {
    std::stringstream ss;
    if (bDetailedLocation) {
        ss << location.file_name() << ':'
           << location.line() << " = "
           << location.function_name() << '\n';
    } else {
        ss << location.function_name() << '\n';
    }
    return ss.str();
}

void Logger::log(LogLevel level, std::string_view channel, std::string_view message) {
    std::puts(formatLog(level, channel, message).c_str());
}

} // namespace util