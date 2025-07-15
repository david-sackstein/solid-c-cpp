#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger(LogLevel level) :
    _filter(level)
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

ILogger& GetConsoleLogger(LogLevel level)
{
    static ConsoleLogger logger(level);
    return logger;
}
