#include "ResourceGuard.h"
#include "demos.h"

#include <iostream>

void demo_hand_rolled_raii() {
    // The constructor acquires the resource and the destructor releases it.
    ResourceGuard guard(new TracedResource(42));
    // This guard does not behave like a pointer yet.
    std::cout << "via get(): " << guard.get()->value << '\n';
}
