#pragma once

#include <injected//ILogger.h>
#include "Memory.h"

#include <string>

namespace refactored {
    // Core calculator base with shared logic for all calculators
    class CalculatorBase {
    public:
        CalculatorBase(injected::ILogger& logger, Memory& memory);

        virtual ~CalculatorBase() = default;

        void calculateAndStore(int a, int b);

        virtual int performOperation(int a, int b);

        virtual void storeInMemory(int value);

        virtual int recallMemory();

        virtual void clearMemory();

        virtual void setMode(std::string mode);

        virtual std::string getMode();

    protected:
        std::string currentMode;
        injected::ILogger& logger;
        Memory& memory;
    };
}
