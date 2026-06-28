#include "FileDeleter.h"
#include "demos.h"

#include <fstream>
#include <iostream>
#include <string>

void demo_custom_deleter() {
    const std::string path = "/tmp/raii_file_ptr.txt";

    {
        // This unique_ptr uses a custom deleter instead of delete.
        FilePtr file(std::fopen(path.c_str(), "w"));
        std::fputs("raii", file.get());
        std::cout << "wrote via FilePtr\n";
        // FileDeleter calls fclose when the pointer goes out of scope.
    }

    // The file can be read here because the custom deleter already closed it.
    std::ifstream in(path);
    std::string line;
    std::getline(in, line);
    std::cout << "read back: " << line << '\n';
}
