#include "FileProcessor.h"
#include "LibraryLoader.h"
#include <logger/ILogger.h>

#include <iostream>
#include <filesystem>
#include <memory>

using namespace shared_object;

// using CreateLoggerFunc = ILogger* (*)(LogLevel);
typedef ILogger* (*CreateLoggerFunc)(LogLevel);

void do_work(ILogger* logger) {
    if (!logger) {
        throw std::runtime_error("Failed to create injected");
    }

    const FileProcessor fileProcessor(*logger);
    fileProcessor.processFile("file.txt");
}

void dynamicLoad(LogLevel level) {
    const LibraryLoader lib("liblogger");
    const auto create_logger = lib.get_function<CreateLoggerFunc>("create_logger_unmangled");
    auto logger = std::unique_ptr<ILogger>(create_logger(level));
    do_work(logger.get());
}

void staticLoad(LogLevel level) {
    auto logger = create_logger(level);
    do_work(logger.get());
}

int main() {
    try {
        dynamicLoad(LogLevel::DEBUG);
        staticLoad(LogLevel::DEBUG);
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << '\n';
        return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
