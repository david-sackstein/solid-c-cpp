#include "TracedResource.h"
#include "demos.h"

#include <iostream>
#include <memory>
#include <vector>

namespace {

std::unique_ptr<TracedResource> make_resource() {
    // Default to unique_ptr because it has zero reference-count overhead.
    return std::make_unique<TracedResource>();
}

}

void demo_when_to_share() {
    {
        // A factory can return unique ownership by default.
        auto owned = make_resource();
        std::cout << "factory returns unique_ptr\n";
        // The resource is released when the sole owner goes out of scope.
    }

    auto resource = std::make_shared<TracedResource>();
    // The first registry takes shared ownership of the resource.
    std::vector<std::shared_ptr<TracedResource>> registry_a{resource};
    // Ownership is shared when there are multiple (equal) owners.
    std::vector<std::shared_ptr<TracedResource>> registry_b{resource};
    // This owner releases its share, but the resource stays alive because the registries still hold it.
    resource.reset();
    // The two registries are now the remaining equal owners.
    std::cout << "registry A and B share, use_count = " << registry_a.front().use_count() << '\n';
}
