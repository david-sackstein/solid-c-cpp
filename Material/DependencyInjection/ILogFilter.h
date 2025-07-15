#pragma once

#include "LogLevel.h"

class ILogFilter
{
public:
    virtual ~ILogFilter() = default;
    virtual bool ShouldLog(LogLevel level) = 0;
};
