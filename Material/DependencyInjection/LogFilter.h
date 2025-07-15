#pragma once

#include "ILogFilter.h"

class LogFilter : public ILogFilter
{
public:
    LogFilter (LogLevel level) :
        _level(level)
    {
    }

    bool ShouldLog(LogLevel level) override
    {
        return level >= _level;
    }

private:

    LogLevel _level;
};
