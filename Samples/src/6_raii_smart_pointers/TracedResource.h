#pragma once

#include <iostream>

// This helper prints acquire and release events so demos show lifetime on stdout.
class TracedResource {
    inline static int next_id_ = 0;
    int id_;

public:
    int value = 0;
    const char *label = "resource";

    TracedResource() : id_(++next_id_) {
        std::cout << "[Resource #" << id_ << " acquired]\n";
    }

    explicit TracedResource(int v) : id_(++next_id_), value(v) {
        std::cout << "[Resource #" << id_ << " acquired]\n";
    }

    ~TracedResource() {
        std::cout << "[Resource #" << id_ << " released]\n";
    }
};
