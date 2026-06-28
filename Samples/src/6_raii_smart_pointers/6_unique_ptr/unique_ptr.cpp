#include "TracedResource.h"
#include "demos.h"

#include <iostream>
#include <memory>

void demo_unique_ptr() {
    // make_unique creates a sole owner with no reference-count overhead.
    auto owner_a = std::make_unique<TracedResource>(99);
    std::cout << "owner A: " << owner_a->value << '\n';

    // A move transfers ownership to the destination.
    auto owner_b = std::move(owner_a);
    std::cout << "owner B: " << owner_b->value << '\n';
    // The source is null after the move.
    std::cout << "owner A after move: " << (owner_a ? "valid" : "null") << '\n';
    // Copying fails because the copy constructor is deleted.
    // auto copy = owner_b;
}
