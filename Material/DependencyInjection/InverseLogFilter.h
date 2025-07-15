#pragma once

#include "ILogFilter.h"

class InverseLogFilter : public ILogFilter
{
public:
    InverseLogFilter(LogLevel level) :
        _level(level)
    {
    }

    bool ShouldLog(LogLevel level) override
    {
        return level < _level;
    }

private:

    LogLevel _level;
};
