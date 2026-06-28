#include "demos.h"
#include "TracedResource.h"

#include <iostream>

namespace {

// An early return skips delete, so the resource leaks.
void leak_on_early_return() {
    auto *r = new TracedResource();
    (void)r;
    std::cout << "leaving early — no release\n";
    return;
    // This line is never reached.
    delete r;
}

// Manual pairing works, but it is easy to get wrong.
void manual_cleanup() {
    auto *r = new TracedResource();
    delete r;
}

}

void demo_manual_leak() {
    // This path leaks because delete is skipped.
    leak_on_early_return();
    // This path releases the resource, but only because delete was not forgotten.
    manual_cleanup();
}
