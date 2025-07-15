#pragma once

#include "LogLevel.h"
#include <string>

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void LogMessage(LogLevel, const std::string& message) = 0;
};

ILogger& GetConsoleLogger(LogLevel);
ILogger& GetTraceLogger(LogLevel);