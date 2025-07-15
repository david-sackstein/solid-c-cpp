#ifdef _WIN32

#include "DynamicLibrary.h"

#include <stdexcept>
#include <filesystem>

DynamicLibrary::DynamicLibrary(const std::string& dll_name) {
    const std::string path = get_dll_path(dll_name);
    handle_ = ::LoadLibraryA(path.c_str());
    if (!handle_) {
        throw std::runtime_error("Failed to load library: " + path);
    }
}

DynamicLibrary::~DynamicLibrary() {
    ::FreeLibrary(handle_);
}

std::string DynamicLibrary::get_dll_path(const std::string& dll_name) {
    const std::filesystem::path currentPath = std::filesystem::current_path();
    const std::filesystem::path dllPath = currentPath / dll_name;
    return dllPath.string();
}

#endif
