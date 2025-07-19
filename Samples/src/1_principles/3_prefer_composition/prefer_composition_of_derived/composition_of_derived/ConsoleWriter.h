#pragma once

#include "IMessageWriter.h"

namespace composition_of_derived {

    class ConsoleWriter final : public IMessageWriter {
    public:
        void writeMessage(const std::string& message) override;
    };

}
