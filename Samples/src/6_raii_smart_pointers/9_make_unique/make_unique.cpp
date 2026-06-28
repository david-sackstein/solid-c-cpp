#include "TracedResource.h"
#include "demos.h"

#include <iostream>
#include <memory>

void demo_make_unique() {
    {
        // Prefer make_unique over calling new directly.
        auto u = std::make_unique<TracedResource>();
        // The destructor runs automatically; never call delete on a wrapped pointer.
    }

    {
        // Prefer make_shared over calling new directly.
        auto s = std::make_shared<TracedResource>();
        // The shared resource is released when the last owner is destroyed.
    }

    // Never create two smart pointers from the same raw pointer.
    // auto raw = new TracedResource();
    // auto a = std::shared_ptr<TracedResource>(raw);
    // auto b = std::shared_ptr<TracedResource>(raw);
    // That would cause a double delete.
}
