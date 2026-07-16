#pragma once
#include <source_location>

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    void printLocation(const std::source_location& location = std::source_location::current());

private:
    bool m_bIsRunning{true};
};
