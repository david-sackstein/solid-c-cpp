#include "demos.h"
#include "TracedResource.h"

#include <iostream>

namespace {

// A stack object's destructor runs automatically when its scope ends.
class StackObject {
public:
    StackObject() { std::cout << "[StackObject acquired]\n"; }
    ~StackObject() { std::cout << "[StackObject released]\n"; }
};

}

void demo_scope_lifetime() {
    {
        // This object is created on the stack, not on the heap.
        StackObject obj;
        std::cout << "inside block\n";
        // The destructor is called here.
    }

    // Declaring a pointer does not allocate memory.
    TracedResource *ptr = nullptr;
    (void)ptr;
    std::cout << "pointer declared — no allocation\n";
}
