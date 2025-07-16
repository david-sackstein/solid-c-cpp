cmake_minimum_required(VERSION 3.31)
project(Samples)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)

set(SAMPLES_PATH src/samples)
set(SHARED_LIBRARY_PATH src/shared_object)
set(TESTS_PATH src/tests)
set(LEGACY_CODE_PATH src/legacy_code)

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
file(GLOB_RECURSE SAMPLES_SOURCES "${SAMPLES_PATH}/*.cpp")
list(FILTER SAMPLES_SOURCES EXCLUDE REGEX "${SHARED_LIBRARY_PATH}/")
add_executable(Samples ${SAMPLES_SOURCES})

# Logger shared library
file(GLOB_RECURSE LOGGER_SOURCES "${SHARED_LIBRARY_PATH}/logger/*.cpp")
add_library(logger SHARED ${LOGGER_SOURCES})
target_include_directories(logger PUBLIC ${SHARED_LIBRARY_PATH}/include)

# FileProcessor executable that uses recorder library
file(GLOB_RECURSE FILEPROCESSOR_SOURCES
    "${SHARED_LIBRARY_PATH}/file_processor/*.cpp"
    "${SHARED_LIBRARY_PATH}/dynamic_loader/*.cpp")
add_executable(fileprocessor ${FILEPROCESSOR_SOURCES}
    src/legacy_code/recorder/RecordingLogger.h)
target_include_directories(fileprocessor PUBLIC
    ${SHARED_LIBRARY_PATH}/include,
    ${SHARED_LIBRARY_PATH}/dynamic_loader)
target_link_libraries(fileprocessor logger)

# Legacy code sources (for tests)
file(GLOB_RECURSE LEGACY_CODE_SOURCES "${LEGACY_CODE_PATH}/*.cpp")

# Test executable
file(GLOB_RECURSE TEST_SOURCES "${TESTS_PATH}/*.cpp")
add_executable(tests ${TEST_SOURCES} ${LEGACY_CODE_SOURCES})
target_link_libraries(tests gtest_main)
target_include_directories(tests PUBLIC ${LEGACY_CODE_PATH})

