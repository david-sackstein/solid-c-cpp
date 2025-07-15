cmake_minimum_required(VERSION 3.31)
project(Samples)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(SHARED_LIBRARY_PATH src/reduce_coupling/5_shared_object)

# By default all symbols in shared libraries are hidden
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Download and add GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Main executable: all files in src/ except for those in SHARED_LIBRARY_PATH
file(GLOB_RECURSE SOURCES "src/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "${SHARED_LIBRARY_PATH}/")
add_executable(Samples ${SOURCES})

# Logger shared library
file(GLOB_RECURSE LOGGER_SOURCES "${SHARED_LIBRARY_PATH}/logger/*.cpp")
add_library(logger SHARED ${LOGGER_SOURCES})
target_include_directories(logger PUBLIC ${SHARED_LIBRARY_PATH}/include)

# FileProcessor executable that uses logger library
file(GLOB_RECURSE FILEPROCESSOR_SOURCES "${SHARED_LIBRARY_PATH}/file_processor/*.cpp")
add_executable(fileprocessor ${FILEPROCESSOR_SOURCES})
target_include_directories(fileprocessor PUBLIC ${SHARED_LIBRARY_PATH}/include)
target_link_libraries(fileprocessor logger)

# Test executable
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(Tests ${TEST_SOURCES})
target_link_libraries(Tests gtest_main)
