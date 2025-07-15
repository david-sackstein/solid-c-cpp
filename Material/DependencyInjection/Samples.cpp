#include "ILogger.h"
#include "InverseLogFilter.h"

int main ()
{
    InverseLogFilter filter(LogLevel::Error);
    ILogger& logger = GetConsoleLogger(filter);
    logger.LogMessage(LogLevel::Debug, "Hello World");
    return 0;
}
