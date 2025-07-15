#include "TraceLogger.h"
#include <windows.h>

TraceLogger::TraceLogger(LogLevel level) :
    LoggerBase(level)
{
}

void TraceLogger::LogMessage(LogLevel level, const std::string& message)
{
    if (!ShouldLog(level))
    {
        return;
    }
    OutputDebugStringA(message.c_str());
}

ILogger& GetTraceLogger(LogLevel level)
{
    static TraceLogger logger(level);
    return logger;
}
