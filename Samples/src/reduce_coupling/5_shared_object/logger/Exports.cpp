#include "Logger.h"

namespace shared_object {

    extern "C"
    EXPORTED std::unique_ptr<ILogger> create_logger(LogLevel logLevel) {
        return std::make_unique<Logger>(logLevel);
    }

}