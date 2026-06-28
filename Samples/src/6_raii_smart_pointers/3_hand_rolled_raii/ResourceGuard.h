#pragma once

#include "TracedResource.h"

// Before smart pointers: an RAII guard with get(), but no pointer operators.
class ResourceGuard {
    TracedResource *ptr_ = nullptr;

public:
    // The constructor takes ownership of the raw pointer.
    explicit ResourceGuard(TracedResource *p) : ptr_(p) {}

    // The resource is released in the destructor.
    ~ResourceGuard() { delete ptr_; }

    // The resource is accessed via a getter, not via * or ->.
    TracedResource *get() const { return ptr_; }

    // Copying is deleted because ownership must stay unique.
    ResourceGuard(const ResourceGuard &) = delete;
    ResourceGuard &operator=(const ResourceGuard &) = delete;
};
