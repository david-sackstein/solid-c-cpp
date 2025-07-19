#include <prefer_composition_of_base/inheritance/FileProcessor.h>

#include <prefer_composition_of_base/composition_of_base/FileProcessor.h>
#include <prefer_composition_of_base/composition_of_base/Logger.h>

#include <prefer_composition_of_derived/duplication/ConsoleLogger.h>
#include <prefer_composition_of_derived/duplication/FileLogger.h>

#include <prefer_composition_of_derived/template_method/BaseLogger.h>
#include <prefer_composition_of_derived/template_method/ConsoleLogger.h>

#include <prefer_composition_of_derived/composition_of_derived/ConsoleWriter.h>
#include <prefer_composition_of_derived/composition_of_derived/FileWriter.h>
#include <prefer_composition_of_derived/composition_of_derived/Logger.h>
#include <prefer_composition_of_derived/template_method/FileLogger.h>

void prefer_composition_of_base() {
    {
        using namespace inheritance;
        FileProcessor fileProcessor(LogLevel::DEBUG);

        fileProcessor.processFile("file.txt");
    }
    {
        using namespace composition_of_base;

        Logger logger(LogLevel::DEBUG);
        FileProcessor fileProcessor(logger);

        fileProcessor.processFile("file.txt");
    }
}

void prefer_composition_of_derived() {
    {
        using namespace duplication;

        ConsoleLogger consoleLogger(LogLevel::DEBUG);
        consoleLogger.log(LogLevel::DEBUG, "This is a test");

        FileLogger fileLogger(LogLevel::DEBUG, "log.txt");
        fileLogger.log(LogLevel::DEBUG, "This is a test");
    }
    {
        using namespace template_method;

        ConsoleLogger consoleLogger(LogLevel::DEBUG);
        consoleLogger.log(LogLevel::DEBUG, "This is a test");

        FileLogger fileLogger(LogLevel::DEBUG, "log.txt");
        fileLogger.log(LogLevel::DEBUG, "This is a test");
    }
    {
        using namespace composition_of_derived;

        ConsoleWriter consoleWriter{};
        Logger logger1(LogLevel::DEBUG, consoleWriter);
        logger1.log(LogLevel::DEBUG, "This is a test");

        FileWriter fileWriter("log.txt");
        Logger logger2(LogLevel::DEBUG, consoleWriter);
        logger2.log(LogLevel::DEBUG, "This is a test");
    }
}

int main() {
}
