#include "TracedResource.h"
#include "demos.h"

#include <iostream>
#include <memory>

void demo_shared_ptr() {
    // make_shared creates the first owner of the resource.
    auto outer = std::make_shared<TracedResource>();
    {
        // A second owner raises the reference count.
        auto inner = outer;
        std::cout << "use_count = " << outer.use_count() << '\n';
        // This owner releases its share, but resource stays alive because outer still holds it.
        inner.reset();
        std::cout << "inner scope ends, use_count = " << outer.use_count() << '\n';
    }
    // The reference count hits zero when outer is destroyed, and the resource is deleted.
}
