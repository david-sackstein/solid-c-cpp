#pragma once

#include "ILogFilter.h"
#include <string>

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void LogMessage(LogLevel, const std::string& message) = 0;
};

ILogger& GetConsoleLogger(ILogFilter&);
ILogger& GetTraceLogger(ILogFilter&);