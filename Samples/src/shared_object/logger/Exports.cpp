#include "Logger.h"

namespace shared_object {

    EXPORTED std::unique_ptr<ILogger> create_logger(LogLevel logLevel) {
        return std::make_unique<Logger>(logLevel);
    }

    extern "C"
    EXPORTED ILogger* create_logger_unmangled(LogLevel logLevel){
        return new Logger(logLevel);
    }
}