#ifndef _WIN32

#include "SharedObject.h"

#include <dlfcn.h>       // For dlopen, dlsym, dlclose
#include <filesystem>

SharedObject::SharedObject(const std::string& so_name) {
    handle_ = dlopen(so_name.c_str(), RTLD_NOW);
    if (!handle_) {
        throw std::runtime_error(std::string("Failed to load shared object: ") + dlerror());
    }
}

SharedObject::~SharedObject() {
    dlclose(handle_);
}

#endif