// Implementation header for POSIX (Linux/macOS): include only in DynamicLibrary.cpp
#pragma once

#include "LibraryLoader.h"

#include <dlfcn.h>
#include <string>
#include <stdexcept>

LibraryLoader::LibraryLoader(const std::string& lib_name) {
    const std::string lib_file_name = lib_name + ".dylib";
    handle_ = dlopen(lib_file_name.c_str(), RTLD_NOW);
    if (!handle_) {
        throw std::runtime_error("Failed to load shared object: " + std::string(dlerror()));
    }
}

LibraryLoader::~LibraryLoader() {
    if (handle_) {
        dlclose(handle_);
    }
}

void* LibraryLoader::get_symbol(const std::string& func_name) const {
    return dlsym(handle_, func_name.c_str());
} 