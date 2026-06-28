#pragma once

#include <iostream>

// This mock connection stands in for a socket or database handle.
class Connection {
public:
    // The connection is acquired in the constructor.
    Connection() { std::cout << "connected\n"; }

    // The connection is released in the destructor, even on an early return.
    ~Connection() { std::cout << "disconnected\n"; }

    void query() const { std::cout << "query executed\n"; }
};
