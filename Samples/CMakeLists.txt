cmake_minimum_required(VERSION 3.31)
project(Samples)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)

# define paths that are reused
set(SHARED_OBJECT_ROOT "src/3_reduce_coupling/5_libraries/shared_object")

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
set(PRINCIPLES_ROOT "src/1_principles")
file(GLOB_RECURSE PRINCIPLES_SOURCES "${PRINCIPLES_ROOT}/*.cpp")
list(FILTER PRINCIPLES_SOURCES EXCLUDE REGEX "${SHARED_OBJECT_ROOT}/")
add_executable(principles ${PRINCIPLES_SOURCES})
target_include_directories(principles PUBLIC "src/1_principles/3_prefer_composition")

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

# Static calculator_lib
set(CALC_STATIC_LIBRARY_ROOT "src/3_reduce_coupling/5_libraries/static_library")
set(CALC_STATIC_LIBRARY_INCLUDE ${CALC_STATIC_LIBRARY_ROOT}/include)
file(GLOB_RECURSE CALC_STATIC_LIBRARY_SOURCES "${CALC_STATIC_LIBRARY_ROOT}/*.cpp")
add_library(calculator_lib STATIC ${CALC_STATIC_LIBRARY_SOURCES})
target_include_directories(calculator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${CALC_STATIC_LIBRARY_INCLUDE})

# calculator_app executable
set(CALCULATOR_APP_ROOT "src/3_reduce_coupling/5_libraries/static_library/calculator_app")
file(GLOB_RECURSE CALCULATOR_APP_SOURCES "${CALCULATOR_APP_ROOT}/*.cpp")
add_executable(calculator_app ${CALCULATOR_APP_SOURCES})
target_link_libraries(calculator_app PRIVATE calculator_lib)
target_include_directories(calculator_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${CALC_STATIC_LIBRARY_INCLUDE})

# interop executable
set(INTEROP_ROOT "src/5_oop_in_c/interop")
file(GLOB_RECURSE INTEROP_SOURCES "${INTEROP_ROOT}/*.cpp" "${INTEROP_ROOT}/*.c")
add_executable(interop ${INTEROP_SOURCES})
target_include_directories(interop PUBLIC ${INTEROP_ROOT})

# oop-in-c executable
set(OOP_IN_C_ROOT "src/5_oop_in_c/interface")
file(GLOB_RECURSE OOP_IN_C_SOURCES "${OOP_IN_C_ROOT}/*.c")
add_executable(oop_in_c ${OOP_IN_C_SOURCES})
target_include_directories(oop_in_c PUBLIC ${OOP_IN_C_ROOT})

# Test executable
set(TESTS_ROOT "src/2_tests")
set(LEGACY_CODE_ROOT "src/4_legacy_code")
file(GLOB_RECURSE LEGACY_CODE_SOURCES "${LEGACY_CODE_ROOT}/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "${TESTS_ROOT}/*.cpp")
add_executable(tests ${TEST_SOURCES} ${LEGACY_CODE_SOURCES})
target_link_libraries(tests gtest_main)
target_include_directories(tests PUBLIC ${LEGACY_CODE_ROOT})
