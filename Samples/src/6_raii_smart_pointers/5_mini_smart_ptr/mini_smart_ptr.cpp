#include "MiniPtr.h"
#include "demos.h"

#include <iostream>

void demo_mini_smart_ptr() {
    // The smart pointer owns the heap resource and will delete it in its destructor.
    MiniPtr ptr(new TracedResource(42));
    // The wrapper can be dereferenced like a raw pointer.
    std::cout << "via * : " << (*ptr).value << '\n';
    // The wrapper supports member access via ->.
    ptr->label = "hello";
    std::cout << "via -> : " << ptr->label << '\n';
    // Copying fails because the copy constructor is deleted.
    // MiniPtr copy(ptr);
}
