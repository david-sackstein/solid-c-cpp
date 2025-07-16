#pragma once

#include "Memory.h"

#include <injected/ILogger.h>

#include <functional>
#include <string>

namespace refactored_again {
    using OperationStrategy = std::function<int(int, int)>;
    using StoreStrategy = std::function<void(int)>;

    class Calculator {
    public:
        Calculator(injected::ILogger& logger, Memory& memory,
                   OperationStrategy operation,
                   StoreStrategy storeStrategy);

        void calculateAndStore(int a, int b);
        int recallMemory();
        void clearMemory();
        void setMode(std::string mode);
        std::string getMode();

    private:
        injected::ILogger& logger;
        Memory& memory;
        OperationStrategy operation;
        StoreStrategy storeStrategy;
        std::string currentMode;
    };
}
