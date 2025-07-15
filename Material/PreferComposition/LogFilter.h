#pragma once

#include "LogLevel.h"

class LogFilter
{
public:
    LogFilter (LogLevel level) :
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
