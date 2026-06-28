#pragma once

#include <cstdio>
#include <memory>

// This stateless deleter calls the API cleanup function.
struct FileDeleter {
    void operator()(FILE *f) const {
        if (f) {
            std::fclose(f);
        }
    }
};

// This type alias gives the RAII wrapper a clear name.
using FilePtr = std::unique_ptr<FILE, FileDeleter>;
