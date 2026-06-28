#include "demos.h"

#include <fstream>
#include <iostream>
#include <mutex>
#include <string>

void demo_raii_file_and_lock() {
    const std::string path = "/tmp/raii_demo.txt";

    {
        // The file is opened in the constructor.
        std::ofstream out(path);
        out << "hello";
        std::cout << "wrote to " << path << '\n';
        // The destructor closes and flushes the file automatically.
    }

    // The file can be read here because the stream already closed and flushed it.
    std::ifstream in(path);
    std::string line;
    std::getline(in, line);
    std::cout << "read back: " << line << '\n';

    std::mutex mtx;
    {
        // The mutex is locked when the lock_guard is created.
        std::lock_guard lock(mtx);
        std::cout << "mutex locked\n";
        std::cout << "critical section\n";
        // The mutex is unlocked when the lock_guard is destroyed.
    }
    std::cout << "mutex unlocked\n";
}
