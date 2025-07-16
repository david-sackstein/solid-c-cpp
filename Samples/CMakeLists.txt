cmake_minimum_required(VERSION 3.31)
project(Samples)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)

# define paths that are reused
set(SHARED_OBJECT_ROOT src/shared_object)

# By default all symbols in shared libraries are hidden
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# Download and add GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Main executable: all files in src/principles
set(PRINCIPLES_ROOT src/principles)
file(GLOB_RECURSE PRINCIPLES_SOURCES "${PRINCIPLES_ROOT}/*.cpp")
list(FILTER PRINCIPLES_SOURCES EXCLUDE REGEX "${SHARED_OBJECT_ROOT}/")
add_executable(principles ${PRINCIPLES_SOURCES})

# Logger shared calculator_lib
file(GLOB_RECURSE LOGGER_SOURCES "${SHARED_OBJECT_ROOT}/logger/*.cpp")
add_library(logger SHARED ${LOGGER_SOURCES})
target_include_directories(logger PUBLIC ${SHARED_OBJECT_ROOT}/include)

# FileProcessor executable that uses injected calculator_lib
set(FILEPROCESSOR_ROOT ${SHARED_OBJECT_ROOT}/file_processor)
set(DYNAMIC_LOADER_ROOT ${SHARED_OBJECT_ROOT}/dynamic_loader)
file(GLOB_RECURSE FILEPROCESSOR_SOURCES "${FILEPROCESSOR_ROOT}/*.cpp" "${DYNAMIC_LOADER_ROOT}/*.cpp")
add_executable(fileprocessor ${FILEPROCESSOR_SOURCES})
target_include_directories(fileprocessor PUBLIC ${SHARED_OBJECT_ROOT}/include ${DYNAMIC_LOADER_ROOT})
target_link_libraries(fileprocessor logger)

# Test executable
set(TESTS_ROOT src/tests)
set(LEGACY_CODE_ROOT src/legacy_code)
file(GLOB_RECURSE LEGACY_CODE_SOURCES "${LEGACY_CODE_ROOT}/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "${TESTS_ROOT}/*.cpp")
add_executable(tests ${TEST_SOURCES} ${LEGACY_CODE_SOURCES})
target_link_libraries(tests gtest_main)
target_include_directories(tests PUBLIC ${LEGACY_CODE_ROOT})

# Static calculator_lib
set(STATIC_LIBRARY_ROOT src/static_library)
set(STATIC_LIBRARY_INCLUDE ${STATIC_LIBRARY_ROOT}/include)
file(GLOB_RECURSE STATIC_LIBRARY_SOURCES "${STATIC_LIBRARY_ROOT}/*.cpp")
add_library(mylibrary STATIC ${STATIC_LIBRARY_SOURCES})
target_include_directories(mylibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${STATIC_LIBRARY_INCLUDE})

# calculator_app executable
set(APP_ROOT src/static_library/calculator_app)
file(GLOB_RECURSE APP_SOURCES "${APP_ROOT}/*.cpp")
add_executable(myapp ${APP_SOURCES})
target_link_libraries(myapp PRIVATE mylibrary)
target_include_directories(myapp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${STATIC_LIBRARY_INCLUDE})

# interop executable
set(INTEROP_ROOT src/interop)
file(GLOB_RECURSE INTEROP_SOURCES "${INTEROP_ROOT}/*.cpp" "${INTEROP_ROOT}/*.c")
add_executable(interop ${INTEROP_SOURCES})
target_include_directories(interop PUBLIC ${INTEROP_ROOT})

