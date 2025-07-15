#include "TraceLogger.h"
#include <windows.h>

TraceLogger::TraceLogger(ILogFilter& filter) :
    _filter(filter)
{
}

void TraceLogger::LogMessage(LogLevel level, const std::string& message)
{
    if (!_filter.ShouldLog(level))
    {
        return;
    }
    OutputDebugStringA(message.c_str());
}

ILogger& GetTraceLogger(ILogFilter& filter)
{
    static TraceLogger logger(filter);
    return logger;
}
