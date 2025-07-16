# Top-level Makefile for Samples project

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -fPIC
LDFLAGS :=

# General directories
SRC_ROOT := src
BUILD_DIR := build
BIN_DIR := bin

# ---------------- Principles ----------------
PRINCIPLES_ROOT := $(SRC_ROOT)/principles
PRINCIPLES_SRCS := $(shell find $(PRINCIPLES_ROOT) -name '*.cpp' 2>/dev/null)
PRINCIPLES_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(PRINCIPLES_SRCS))

# ---------------- Logger (Shared Object) ----------------
SHARED_OBJECT_ROOT := $(SRC_ROOT)/shared_object
LOGGER_SRCS := $(shell find $(SHARED_OBJECT_ROOT)/logger -name '*.cpp' 2>/dev/null)
LOGGER_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(LOGGER_SRCS))

# ---------------- FileProcessor ----------------
FILEPROCESSOR_SRCS := \
	$(shell find $(SHARED_OBJECT_ROOT)/file_processor -name '*.cpp' 2>/dev/null) \
	$(shell find $(SHARED_OBJECT_ROOT)/dynamic_loader -name '*.cpp' 2>/dev/null)
FILEPROCESSOR_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(FILEPROCESSOR_SRCS))

# ---------------- Tests ----------------
TESTS_ROOT := $(SRC_ROOT)/tests
TEST_SRCS := $(shell find $(TESTS_ROOT) -name '*.cpp' 2>/dev/null)
TEST_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))

# ---------------- Legacy Code ----------------
LEGACY_CODE_ROOT := $(SRC_ROOT)/legacy_code
LEGACY_CODE_SRCS := $(shell find $(LEGACY_CODE_ROOT) -name '*.cpp' 2>/dev/null)
LEGACY_CODE_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(LEGACY_CODE_SRCS))

# ---------------- Static Library ----------------
STATIC_LIBRARY_ROOT := src/static_library/calculator_lib
STATIC_LIBRARY_INCLUDE := src/static_library/include
STATIC_LIBRARY_SRCS := $(shell find $(STATIC_LIBRARY_ROOT) -name '*.cpp' 2>/dev/null)
STATIC_LIBRARY_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(STATIC_LIBRARY_SRCS))
STATIC_LIBRARY := $(BUILD_DIR)/libcalculator_lib.a

# ---------------- App (uses Static Library) ----------------
APP_ROOT := src/static_library/calculator_app
APP_SRCS := $(shell find $(APP_ROOT) -name '*.cpp' 2>/dev/null)
APP_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(APP_SRCS))
APP_BIN := $(BIN_DIR)/calculator_app
LIBRARY_INCLUDE := -I$(STATIC_LIBRARY_INCLUDE)

# ---------------- Interop ----------------
INTEROP_ROOT := src/interop
INTEROP_SRCS := $(shell find $(INTEROP_ROOT) -name '*.cpp' -o -name '*.c' 2>/dev/null)
INTEROP_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(filter %.cpp,$(INTEROP_SRCS))) \
                $(patsubst %.c,$(BUILD_DIR)/%.o,$(filter %.c,$(INTEROP_SRCS)))
INTEROP_BIN := $(BIN_DIR)/interop

# ---------------- Include Paths ----------------
INCLUDES := \
	-I$(SHARED_OBJECT_ROOT)/include \
	-I$(SHARED_OBJECT_ROOT)/include/logger \
	-I$(SHARED_OBJECT_ROOT)/dynamic_loader \
	-I$(SHARED_OBJECT_ROOT)/file_processor \
	-I$(SHARED_OBJECT_ROOT)/logger \
	-I$(PRINCIPLES_ROOT) \
	-I$(LEGACY_CODE_ROOT) \
	-I$(STATIC_LIBRARY_INCLUDE)

# ---------------- GoogleTest ----------------
GTEST_DIR := third_party/googletest
GTEST_BUILD_DIR := $(GTEST_DIR)/build
GTEST_LIB := $(GTEST_BUILD_DIR)/lib/libgtest.a
GTEST_MAIN_LIB := $(GTEST_BUILD_DIR)/lib/libgtest_main.a
GTEST_INCLUDE := $(GTEST_DIR)/googletest/include
INCLUDES += -I$(GTEST_INCLUDE)

.PHONY: all clean gtest principles liblogger fileprocessor tests calculator_lib calculator_app interop

all: gtest principles liblogger fileprocessor tests calculator_lib calculator_app interop

gtest:
	@if [ ! -d $(GTEST_DIR) ]; then \
		git clone --depth 1 https://github.com/google/googletest.git $(GTEST_DIR); \
	fi
	@mkdir -p $(GTEST_BUILD_DIR)
	cd $(GTEST_BUILD_DIR) && cmake .. && $(MAKE)

principles: $(PRINCIPLES_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)/principles $^

liblogger: $(LOGGER_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $(BIN_DIR)/liblogger.so $^

fileprocessor: $(FILEPROCESSOR_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)/fileprocessor $^ -L$(BIN_DIR) -llogger

tests: gtest $(TEST_OBJS) $(LEGACY_CODE_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)/tests $(TEST_OBJS) $(LEGACY_CODE_OBJS) $(GTEST_LIB) $(GTEST_MAIN_LIB) -lpthread
	$(BIN_DIR)/tests

# Ensure gtest is built before any test objects
$(TEST_OBJS): gtest

calculator_lib: $(STATIC_LIBRARY_OBJS)
	@mkdir -p $(BUILD_DIR)/static_library/library
	ar rcs $(STATIC_LIBRARY) $^

calculator_app: $(APP_OBJS) $(STATIC_LIBRARY)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LIBRARY_INCLUDE) -o $(APP_BIN) $(APP_OBJS) $(STATIC_LIBRARY)

interop: $(INTEROP_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(INTEROP_BIN) $(INTEROP_OBJS)

# Pattern rule for building objects
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)