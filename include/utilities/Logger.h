#pragma once
#include <source_location>
#include <string_view>

namespace util {

class Logger
{
public:
    static void logDebug(std::string_view channelName, std::string_view message);
    static void logError(std::string_view channelName, std::string_view message);
    static void logException(std::string_view channelName, std::string_view message);
    static void logInfo(std::string_view channelName, std::string_view message);
    static void logVerbose(std::string_view channelName, std::string_view message);
    static void logWarning(std::string_view channelName, std::string_view message);

    static void location(const std::source_location& location =
                         std::source_location::current());

    static void detailedLocation(const std::source_location& location =
                                 std::source_location::current());

private:
    enum class LogLevel {
        eDebug,
        eError,
        eException,
        eInfo,
        eVerbose,
        eWarning
    };

    static constexpr std::string_view enumToString(LogLevel level) noexcept;

    static std::string formatLog(LogLevel level,
                                 std::string_view channel,
                                 std::string_view message);

    static std::string formatLocation(const std::source_location& location =
                                      std::source_location::current(),
                                      bool bDetailedLocation = false);

    static void log(LogLevel level, std::string_view channel, std::string_view message);
};

} // namespace util
