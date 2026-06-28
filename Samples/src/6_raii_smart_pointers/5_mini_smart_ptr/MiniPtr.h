#pragma once

#include "TracedResource.h"

// RAII plus operator* and operator->, so it behaves like a raw pointer.
class MiniPtr {
    TracedResource *ptr_ = nullptr;

public:
    // The constructor takes ownership of the raw pointer.
    explicit MiniPtr(TracedResource *p) : ptr_(p) {}

    // The destructor releases the owned resource.
    ~MiniPtr() { delete ptr_; }

    TracedResource &operator*() const { return *ptr_; }

    TracedResource *operator->() const { return ptr_; }

    // Copying is deleted to enforce unique ownership.
    MiniPtr(const MiniPtr &) = delete;
    MiniPtr &operator=(const MiniPtr &) = delete;
};
