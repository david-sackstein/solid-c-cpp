#include "FileProcessor.h"
#include "DynamicLibrary.h"
#include <logger/ILogger.h>

#include <iostream>
#include <filesystem>
#include <memory>

using namespace shared_object;

// using CreateLoggerFunc = std::unique_ptr<ILogger> (*)(LogLevel);
typedef std::unique_ptr<ILogger> (*CreateLoggerFunc)(LogLevel);

void do_work(CreateLoggerFunc create_logger) {
    const std::unique_ptr<ILogger> logger = create_logger(LogLevel::DEBUG);
    if (!logger) {
        throw std::runtime_error("Failed to create logger");
    }

    const FileProcessor fileProcessor(*logger);
    fileProcessor.processFile("file.txt");
}

void dynamicLoad() {
    const DynamicLibrary lib("liblogger.dll");
    const auto create_logger = lib.get_function<CreateLoggerFunc>("create_logger");
    do_work(create_logger);
}

void staticLoad() {
    do_work(create_logger);
}

int main() {
    try {
        dynamicLoad();
        staticLoad();
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << '\n';
        return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
