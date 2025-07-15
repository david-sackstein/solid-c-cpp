#pragma once

#include "ILogger.h"
#include "LogFilter.h"

class TraceLogger : public ILogger
{
public:
    TraceLogger(LogLevel level);
    void LogMessage(LogLevel level, const std::string& message) override;

private:
    LogFilter _filter;
};
