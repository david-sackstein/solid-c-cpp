#include "ILogger.h"

int main ()
{
    ILogger& logger = GetConsoleLogger(LogLevel::Debug);
    logger.LogMessage(LogLevel::Error, "Hello World");
    return 0;
}