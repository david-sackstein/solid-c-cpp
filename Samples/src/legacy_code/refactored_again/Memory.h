#pragma once

namespace refactored_again {
    class Memory {
    public:
        Memory();

        void store(int value);
        int recall() const;
        void clear();

    private:
        int storedValue;
    };
}
