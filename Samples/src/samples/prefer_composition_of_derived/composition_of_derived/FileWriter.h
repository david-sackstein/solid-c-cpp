#pragma once

#include "IMessageWriter.h"

namespace composition_of_derived {

    class FileWriter final : public IMessageWriter {
        std::string fileName_;

    public:
        explicit FileWriter(const std::string& fileName);

        void writeMessage(const std::string& message) override;
    };

}
