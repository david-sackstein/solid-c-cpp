#pragma once

#include "TracedResource.h"

#include <iostream>
#include <memory>
#include <string>

struct Node {
    std::shared_ptr<TracedResource> resource;
    std::shared_ptr<Node> child;
    // A shared_ptr back-reference causes a reference cycle.
    std::shared_ptr<Node> parent;
    // A weak_ptr back-reference breaks the cycle.
    std::weak_ptr<Node> parent_weak;
};

// With cyclical shared_ptr references, the nodes are destroyed but the resource is never released.
inline void run_cycle_demo() {
    auto parent = std::make_shared<Node>();
    parent->resource = std::make_shared<TracedResource>();
    parent->child = std::make_shared<Node>();
    // This creates a cycle between parent and child.
    parent->child->parent = parent;

    // Dropping our handle is not enough because the cycle still keeps the nodes alive.
    parent.reset();
    std::cout << "resource still alive — leak\n";
}

// A weak_ptr observes the resource without owning it, so the cycle is broken and the resource is released.
inline void run_weak_demo() {
    // This weak_ptr will later show whether the resource still exists.
    std::weak_ptr<TracedResource> weak;
    {
        auto parent = std::make_shared<Node>();
        parent->resource = std::make_shared<TracedResource>();
        parent->resource->label = "parent";
        parent->child = std::make_shared<Node>();
        // The child holds a non-owning back-reference to the parent.
        parent->child->parent_weak = parent;

        // The weak_ptr must be upgraded to a shared_ptr before it can be used.
        if (auto p = parent->child->parent_weak.lock()) {
            std::cout << "child sees parent: " << p->resource->label << '\n';
        }
        // We keep a weak observer to test access after the owners are gone.
        weak = parent->resource;
        std::cout << "parent scope ends\n";
    }
    // lock() returns empty once the resource is gone.
    std::cout << "lock after release: " << (weak.lock() ? "alive" : "expired") << '\n';
}
