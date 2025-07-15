#pragma once

#include <string>

namespace composition_of_derived {

    class IMessageWriter {
    public:
        virtual ~IMessageWriter() = default;

        virtual void writeMessage(const std::string& message) = 0;
    };

}