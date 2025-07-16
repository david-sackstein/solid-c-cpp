#include "Memory.h"

namespace refactored_again {
    Memory::Memory() : storedValue(0) {}

    void Memory::store(int value) {
        storedValue = value;
    }

    int Memory::recall() const {
        return storedValue;
    }

    void Memory::clear() {
        storedValue = 0;
    }
}
