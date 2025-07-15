#pragma once

#include <string>
#include <stdexcept>

class LibraryLoader {
    void* handle_;

    void* get_symbol(const std::string& func_name) const; // implemented in .cpp

public:

    explicit LibraryLoader(const std::string& lib_name);
    ~LibraryLoader();

    LibraryLoader(const LibraryLoader&) = delete;
    LibraryLoader& operator=(const LibraryLoader&) = delete;

    template<typename FuncType>
    FuncType get_function(const std::string& func_name) const {
        void* sym = get_symbol(func_name);
        if (!sym) throw std::runtime_error("Failed to get function: " + func_name);
        return reinterpret_cast<FuncType>(sym);
    }
};
