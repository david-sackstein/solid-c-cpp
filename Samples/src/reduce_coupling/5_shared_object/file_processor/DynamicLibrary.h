#pragma once

#ifdef _WIN32

#include <windows.h>
#include <string>
#include <stdexcept>

class DynamicLibrary {
    HMODULE handle_;

public:
    explicit DynamicLibrary(const std::string& dll_name);
    ~DynamicLibrary();

    DynamicLibrary(const DynamicLibrary&) = delete;
    DynamicLibrary& operator=(const DynamicLibrary&) = delete;

    template<typename FuncType>
    FuncType get_function(const std::string& func_name) const {
        FARPROC proc = GetProcAddress(handle_, func_name.c_str());
        if (!proc) {
            throw std::runtime_error("Failed to get function: " + func_name);
        }
        return reinterpret_cast<FuncType>(proc);
    }

private:
    static std::string get_dll_path(const std::string& dll_name);
};

#endif
