#include "demos.h"

#include <cstring>
#include <iostream>

struct DemoEntry {
    const char *id;
    const char *title;
    void (*run)();
};

constexpr DemoEntry demos[] = {
    {"01", "manual leak (slide 3)", demo_manual_leak},
    {"02", "scope lifetime (slide 4)", demo_scope_lifetime},
    {"03", "RAII guard — before smart pointer (slide 5)", demo_hand_rolled_raii},
    {"04", "ownership contracts (slide 6)", demo_ownership_contracts},
    {"05", "mini smart pointer — after (slide 7)", demo_mini_smart_ptr},
    {"06", "unique_ptr (slide 9)", demo_unique_ptr},
    {"07", "shared_ptr (slide 10)", demo_shared_ptr},
    {"08", "weak_ptr (slide 11)", demo_weak_ptr},
    {"08-cycle", "weak_ptr cycle leak (slide 11)", demo_weak_ptr_cycle},
    {"09", "make_unique (slide 12)", demo_make_unique},
    {"10", "when to share (slide 13)", demo_when_to_share},
    {"11", "passing (slide 14)", demo_passing},
    {"12", "file and lock (slide 15)", demo_raii_file_and_lock},
    {"13", "connection (slide 16)", demo_raii_connection},
    {"14", "custom deleter (slide 17)", demo_custom_deleter},
};

void print_usage() {
    std::cout << "Usage: raii <id> | raii all\n\nSamples:\n";
    for (const auto &demo : demos) {
        std::cout << "  " << demo.id << "  " << demo.title << '\n';
    }
}

void run_all() {
    for (const auto &demo : demos) {
        std::cout << "========== " << demo.id << " " << demo.title << " ==========\n";
        demo.run();
        std::cout << '\n';
    }
}

const DemoEntry *find_demo(const char *id) {
    for (const auto &demo : demos) {
        if (std::strcmp(demo.id, id) == 0) {
            return &demo;
        }
    }
    return nullptr;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return argc == 1 ? 0 : 1;
    }

    if (std::strcmp(argv[1], "all") == 0) {
        run_all();
        return 0;
    }

    if (const DemoEntry *demo = find_demo(argv[1])) {
        demo->run();
        return 0;
    }

    std::cout << "Unknown sample: " << argv[1] << '\n';
    print_usage();
    return 1;
}
