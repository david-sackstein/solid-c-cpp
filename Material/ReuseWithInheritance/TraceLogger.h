#pragma once

#include "LoggerBase.h"

class TraceLogger : public LoggerBase
{
public:
    TraceLogger(LogLevel level);
    void LogMessage(LogLevel level, const std::string& message) override;
};
