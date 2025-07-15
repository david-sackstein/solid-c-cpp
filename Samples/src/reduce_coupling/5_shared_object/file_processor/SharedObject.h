#pragma once

#ifndef _WIN32

#include <string>
#include <stdexcept>

class SharedObject {
    void* handle_ = nullptr;

public:
    explicit SharedObject(const std::string& so_name);
    ~SharedObject();

    SharedObject(const SharedObject&) = delete;
    SharedObject& operator=(const SharedObject&) = delete;

    template<typename FuncType>
    FuncType get_function(const std::string& func_name) const {
        void* sym = dlsym(handle_, func_name.c_str());
        if (!sym) {
            throw std::runtime_error("Failed to get function: " + func_name);
        }
        return reinterpret_cast<FuncType>(sym);
    }
};

#endif