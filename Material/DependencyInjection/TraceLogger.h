#pragma once

#include "ILogger.h"

class TraceLogger : public ILogger
{
public:
    TraceLogger(ILogFilter& filter);
    void LogMessage(LogLevel level, const std::string& message) override;

private:
    ILogFilter& _filter;
};
