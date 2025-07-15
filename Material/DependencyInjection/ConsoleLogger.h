#pragma once

#include "ILogger.h"

class ConsoleLogger : public ILogger
{
public:
    ConsoleLogger(ILogFilter& filter);
    void LogMessage(LogLevel level, const std::string& message) override;

private:
    ILogFilter& _filter;
};
