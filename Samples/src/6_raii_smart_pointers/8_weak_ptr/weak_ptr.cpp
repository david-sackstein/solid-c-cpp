#include "Node.h"
#include "demos.h"

void demo_weak_ptr() {
    // A weak_ptr breaks cycles, and lock() checks whether the resource still exists.
    run_weak_demo();
}

void demo_weak_ptr_cycle() {
    // A shared_ptr cycle prevents the resource from ever being released.
    run_cycle_demo();
}
