#pragma once

#include "ILogger.h"

class LoggerBase : public ILogger
{
public:
    LoggerBase (LogLevel level) :
        _level(level)
    {
    }

    bool ShouldLog(LogLevel level)
    {
        return level >= _level;
    }

private:

    LogLevel _level;
};
