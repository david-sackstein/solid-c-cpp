# Top-level Makefile for Samples project

# ----- Compiler and flags -----
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -fPIC
LDFLAGS :=

# ----- General directories -----
SRC_ROOT := src
BUILD_DIR := build
BIN_DIR := bin

# ----- Output file variables -----
PRINCIPLES_BIN := $(BIN_DIR)/principles
LOGGER_SO := $(BIN_DIR)/liblogger.so
FILEPROCESSOR_BIN := $(BIN_DIR)/fileprocessor
TESTS_BIN := $(BIN_DIR)/tests
CALCULATOR_LIB_A := $(BUILD_DIR)/libcalculator_lib.a
CALCULATOR_APP_BIN := $(BIN_DIR)/calculator_app
INTEROP_BIN := $(BIN_DIR)/interop
OOP_IN_C_BIN := $(BIN_DIR)/oop_in_c

# OOP in C (interface)
OOP_IN_C_ROOT := src/5_oop_in_c/interface
OOP_IN_C_SRCS := $(shell find $(OOP_IN_C_ROOT) -name '*.c' 2>/dev/null)
OOP_IN_C_OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(OOP_IN_C_SRCS))

# Principles
PRINCIPLES_ROOT := $(SRC_ROOT)/1_principles
PRINCIPLES_SRCS := $(shell find $(PRINCIPLES_ROOT) -name '*.cpp' 2>/dev/null)
PRINCIPLES_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(PRINCIPLES_SRCS))

# Logger (Shared Object)
SHARED_OBJECT_ROOT := $(SRC_ROOT)/3_reduce_coupling/5_libraries/shared_object
LOGGER_SRCS := $(shell find $(SHARED_OBJECT_ROOT)/logger -name '*.cpp' 2>/dev/null)
LOGGER_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(LOGGER_SRCS))

# FileProcessor
FILEPROCESSOR_SRCS := \
	$(shell find $(SHARED_OBJECT_ROOT)/file_processor -name '*.cpp' 2>/dev/null) \
	$(shell find $(SHARED_OBJECT_ROOT)/dynamic_loader -name '*.cpp' 2>/dev/null)
FILEPROCESSOR_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(FILEPROCESSOR_SRCS))

# Tests
TESTS_ROOT := $(SRC_ROOT)/2_tests
TEST_SRCS := $(shell find $(TESTS_ROOT) -name '*.cpp' 2>/dev/null)
TEST_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))
$(TEST_OBJS): gtest

# Legacy Code
LEGACY_CODE_ROOT := $(SRC_ROOT)/4_legacy_code
LEGACY_CODE_SRCS := $(shell find $(LEGACY_CODE_ROOT) -name '*.cpp' 2>/dev/null)
LEGACY_CODE_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(LEGACY_CODE_SRCS))

# Static Library
CALC_STATIC_LIBRARY_ROOT := src/3_reduce_coupling/5_libraries/static_library/calculator_lib
CALC_STATIC_LIBRARY_INCLUDE := src/3_reduce_coupling/5_libraries/static_library/include
CALC_STATIC_LIBRARY_SRCS := $(shell find $(CALC_STATIC_LIBRARY_ROOT) -name '*.cpp' 2>/dev/null)
CALC_STATIC_LIBRARY_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(CALC_STATIC_LIBRARY_SRCS))

# Calculator app (uses Static Library)
CALCULATOR_APP_ROOT := src/3_reduce_coupling/5_libraries/static_library/calculator_app
CALCULATOR_APP_SRCS := $(shell find $(CALCULATOR_APP_ROOT) -name '*.cpp' 2>/dev/null)
CALCULATOR_APP_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(CALCULATOR_APP_SRCS))
LIBRARY_INCLUDE := -I$(CALC_STATIC_LIBRARY_INCLUDE)

# Interop
INTEROP_ROOT := src/5_oop_in_c/interop
INTEROP_SRCS := $(shell find $(INTEROP_ROOT) -name '*.cpp' -o -name '*.c' 2>/dev/null)
INTEROP_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(filter %.cpp,$(INTEROP_SRCS))) \
                $(patsubst %.c,$(BUILD_DIR)/%.o,$(filter %.c,$(INTEROP_SRCS)))

# ----- Shared Object Subfolders -----
SHARED_OBJECT_INCLUDE := $(SHARED_OBJECT_ROOT)/include
SHARED_OBJECT_INCLUDE_LOGGER := $(SHARED_OBJECT_ROOT)/include/logger
SHARED_OBJECT_DYNAMIC_LOADER := $(SHARED_OBJECT_ROOT)/dynamic_loader
SHARED_OBJECT_FILE_PROCESSOR := $(SHARED_OBJECT_ROOT)/file_processor
SHARED_OBJECT_LOGGER := $(SHARED_OBJECT_ROOT)/logger

# ----- Prefer Composition Subfolders -----
PREFER_COMPOSITION_ROOT := src/1_principles/3_prefer_composition
PREFER_COMPOSITION_BASE := $(PREFER_COMPOSITION_ROOT)/prefer_composition_of_base
PREFER_COMPOSITION_DERIVED := $(PREFER_COMPOSITION_ROOT)/prefer_composition_of_derived

# ----- Include Paths -----
INCLUDES := \
	-I$(SHARED_OBJECT_INCLUDE) \
	-I$(SHARED_OBJECT_INCLUDE_LOGGER) \
	-I$(SHARED_OBJECT_DYNAMIC_LOADER) \
	-I$(SHARED_OBJECT_FILE_PROCESSOR) \
	-I$(SHARED_OBJECT_LOGGER) \
	-I$(PRINCIPLES_ROOT) \
	-I$(LEGACY_CODE_ROOT) \
	-I$(CALC_STATIC_LIBRARY_INCLUDE) \
	-I$(PREFER_COMPOSITION_ROOT) \
	-I$(PREFER_COMPOSITION_BASE) \
	-I$(PREFER_COMPOSITION_DERIVED)

# GoogleTest
GTEST_DIR := third_party/googletest
GTEST_BUILD_DIR := $(GTEST_DIR)/build
GTEST_LIB := $(GTEST_BUILD_DIR)/lib/libgtest.a
GTEST_MAIN_LIB := $(GTEST_BUILD_DIR)/lib/libgtest_main.a
GTEST_INCLUDE := $(GTEST_DIR)/googletest/include
INCLUDES += -I$(GTEST_INCLUDE)

# ----- .PHONY and all -----
.PHONY: all clean gtest principles

all: $(PRINCIPLES_BIN) $(LOGGER_SO) $(FILEPROCESSOR_BIN) $(CALCULATOR_LIB_A) $(CALCULATOR_APP_BIN) $(INTEROP_BIN) $(OOP_IN_C_BIN) $(TESTS_BIN)
	@true

# ----- Rules (in the same order as the output file variables) -----
$(PRINCIPLES_BIN): $(PRINCIPLES_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

$(LOGGER_SO): $(LOGGER_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

$(FILEPROCESSOR_BIN): $(FILEPROCESSOR_OBJS) $(LOGGER_SO)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ -L$(BIN_DIR) -llogger

$(TESTS_BIN): gtest $(TEST_OBJS) $(LEGACY_CODE_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(TEST_OBJS) $(LEGACY_CODE_OBJS) $(GTEST_LIB) $(GTEST_MAIN_LIB) -lpthread
	$@

$(CALCULATOR_LIB_A): $(CALC_STATIC_LIBRARY_OBJS)
	@mkdir -p $(BUILD_DIR)/static_library/library
	ar rcs $@ $^

$(CALCULATOR_APP_BIN): $(CALCULATOR_APP_OBJS) $(CALCULATOR_LIB_A)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LIBRARY_INCLUDE) -o $@ $(CALCULATOR_APP_OBJS) $(CALCULATOR_LIB_A)

$(INTEROP_BIN): $(INTEROP_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(INTEROP_OBJS)

$(OOP_IN_C_BIN): $(OOP_IN_C_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(OOP_IN_C_OBJS)

# ----- Pattern rules and clean -----
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)