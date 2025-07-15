#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger(ILogFilter& filter) :
    _filter(filter)
{
}

void ConsoleLogger::LogMessage(LogLevel level, const std::string& message)
{
    if (!_filter.ShouldLog(level))
    {
        return;
    }
    printf("%s\n", message.c_str());
}

ILogger& GetConsoleLogger(ILogFilter& filter)
{
    static ConsoleLogger logger(filter);
    return logger;
}
