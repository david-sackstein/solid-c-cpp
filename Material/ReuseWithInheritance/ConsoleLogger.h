#pragma once

#include "LoggerBase.h"

class ConsoleLogger : public LoggerBase
{
public:
    ConsoleLogger(LogLevel level);
    void LogMessage(LogLevel level, const std::string& message) override;
};
