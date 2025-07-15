#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger(LogLevel level) :
    LoggerBase(level)
{
}

void ConsoleLogger::LogMessage(LogLevel level, const std::string& message)
{
    if (!ShouldLog(level))
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
