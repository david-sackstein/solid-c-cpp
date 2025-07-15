#pragma once

#include <string>

enum class LogLevel
{
    Debug = 0,
    Error
};

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void LogMessage(LogLevel, const std::string& message) = 0;
};

ILogger& GetConsoleLogger(LogLevel);
ILogger& GetTraceLogger(LogLevel);