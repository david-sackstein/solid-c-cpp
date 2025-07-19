// Implementation header for Windows: include only in DynamicLibrary.cpp
#pragma once

#include "LibraryLoader.h"

#include <windows.h>
#include <string>
#include <stdexcept>

LibraryLoader::LibraryLoader(const std::string& lib_name) {
    const std::string lib_file_name = lib_name + ".dll";
    handle_ = static_cast<void*>(LoadLibraryA(lib_file_name.c_str()));
    if (!handle_) {
        throw std::runtime_error("Failed to load calculator_lib: " + lib_file_name);
    }
}

LibraryLoader::~LibraryLoader() {
    if (handle_) {
        FreeLibrary(static_cast<HMODULE>(handle_));
    }
}

void* LibraryLoader::get_symbol(const std::string& func_name) const {
    return reinterpret_cast<void*>(GetProcAddress(static_cast<HMODULE>(handle_), func_name.c_str()));
} 