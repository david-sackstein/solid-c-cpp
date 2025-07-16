#pragma once

#include <injected/ILogger.h>

#include <string>

namespace inject_logger {
    // Core calculator base with shared logic for all calculators
    class CalculatorBase {
    public:
        CalculatorBase(injected::ILogger& logger);

        virtual ~CalculatorBase() = default;

        void calculateAndStore(int a, int b);

        virtual int performOperation(int a, int b);

        virtual void storeInMemory(int value);

        virtual int recallMemory();

        virtual void clearMemory();

        virtual void setMode(std::string mode);

        virtual std::string getMode();

    protected:
        int memory;
        std::string currentMode;
        injected::ILogger& logger;
    };
}