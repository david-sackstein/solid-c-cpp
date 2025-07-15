#pragma once

#include "LogFilter.h"
#include "ILogger.h"

class ConsoleLogger : public ILogger
{
public:
    ConsoleLogger(LogLevel level);
    void LogMessage(LogLevel level, const std::string& message) override;

private:
    LogFilter _filter;
};
