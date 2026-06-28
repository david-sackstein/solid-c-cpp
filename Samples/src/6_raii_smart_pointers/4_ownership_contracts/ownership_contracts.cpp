#include "TracedResource.h"
#include "demos.h"

#include <iostream>
#include <memory>

void demo_ownership_contracts() {
    // Unique ownership means only one owner holds the resource at a time.
    auto unique = std::make_unique<TracedResource>();
    std::cout << "unique: before move, owner holds resource\n";

    // Ownership transfers to moved, and the source becomes null.
    auto moved = std::move(unique);
    std::cout << "unique: after move, source is " << (unique ? "valid" : "null") << '\n';

    {
        auto a = std::make_shared<TracedResource>();
        // With shared ownership, multiple owners share one resource and the ref count tracks its lifetime.
        auto b = a;
        std::cout << "shared: use_count = " << a.use_count() << '\n';
        // This owner releases its share, but the resource stays alive because a still holds it.
        b.reset();
        std::cout << "shared: use_count = " << a.use_count() << '\n';
        // The resource is released when the last owner is gone.
    }
}
