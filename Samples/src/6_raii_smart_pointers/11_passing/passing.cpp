#include "TracedResource.h"
#include "demos.h"

#include <iostream>
#include <memory>

namespace {

// Pass by const reference when the function only observes a resource that is guaranteed to exist.
void observe(const TracedResource &r) {
    std::cout << "observe via const&: " << r.label << '\n';
}

// Pass a raw pointer when the observer is optional and null is a valid value.
void find(TracedResource *r) {
    if (r) {
        std::cout << "observe via *: " << r->label << '\n';
    } else {
        std::cout << "observe via nullptr: skipped\n";
    }
}

// Pass a shared_ptr by value only when the callee is meant to take shared ownership.
void share(std::shared_ptr<TracedResource> r) {
    std::cout << "share: use_count now " << r.use_count() << '\n';
}

}

void demo_passing() {
    // This shared_ptr is the owner of the resource.
    auto owner = std::make_shared<TracedResource>();
    owner->label = "ok";
    // The caller borrows via a reference, so the reference count does not change.
    observe(*owner);
    // The caller borrows via a raw pointer, which must not outlive the owner.
    find(owner.get());
    // A null pointer means the observer has nothing to observe.
    find(nullptr);
    // The callee takes shared ownership, so the reference count increments.
    share(owner);
}
