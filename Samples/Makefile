# Top-level Makefile for Samples project

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -fPIC
LDFLAGS :=

# Directories
BUILD_DIR := build
BIN_DIR := bin
SRC_ROOT := src
SHARED_OBJECT_ROOT := $(SRC_ROOT)/shared_object
SAMPLES_ROOT := $(SRC_ROOT)/samples
TESTS_ROOT := $(SRC_ROOT)/tests
LEGACY_CODE_ROOT := $(SRC_ROOT)/legacy_code

# Include paths
INCLUDES := \
	-I$(SHARED_OBJECT_ROOT)/include \
	-I$(SHARED_OBJECT_ROOT)/include/logger \
	-I$(SHARED_OBJECT_ROOT)/dynamic_loader \
	-I$(SHARED_OBJECT_ROOT)/file_processor \
	-I$(SHARED_OBJECT_ROOT)/logger \
	-I$(SAMPLES_ROOT) \
	-I$(LEGACY_CODE_ROOT)

# GoogleTest variables
GTEST_DIR := third_party/googletest
GTEST_BUILD_DIR := $(GTEST_DIR)/build
GTEST_LIB := $(GTEST_BUILD_DIR)/lib/libgtest.a
GTEST_MAIN_LIB := $(GTEST_BUILD_DIR)/lib/libgtest_main.a
GTEST_INCLUDE := $(GTEST_DIR)/googletest/include

# Add GTEST_INCLUDE to INCLUDES
INCLUDES += -I$(GTEST_INCLUDE)

# Find all sources recursively (suppress errors if directory doesn't exist)
SAMPLES_SRCS := $(shell find $(SAMPLES_ROOT) -name '*.cpp' 2>/dev/null)
LOGGER_SRCS := $(shell find $(SHARED_OBJECT_ROOT)/logger -name '*.cpp' 2>/dev/null)
FILEPROCESSOR_SRCS := \
	$(shell find $(SHARED_OBJECT_ROOT)/file_processor -name '*.cpp' 2>/dev/null) \
	$(shell find $(SHARED_OBJECT_ROOT)/dynamic_loader -name '*.cpp' 2>/dev/null)
LEGACY_CODE_SRCS := $(shell find $(LEGACY_CODE_ROOT) -name '*.cpp' 2>/dev/null)
TEST_SRCS := $(shell find $(TESTS_ROOT) -name '*.cpp' 2>/dev/null)

# Object file naming (mirroring source tree under build/)
SAMPLES_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SAMPLES_SRCS))
LOGGER_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(LOGGER_SRCS))
FILEPROCESSOR_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(FILEPROCESSOR_SRCS))
TEST_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))
LEGACY_CODE_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(LEGACY_CODE_SRCS))

.PHONY: all clean gtest samples liblogger fileprocessor tests legacy_code

all: gtest samples liblogger fileprocessor tests legacy_code

gtest:
	@if [ ! -d $(GTEST_DIR) ]; then \
		git clone --depth 1 https://github.com/google/googletest.git $(GTEST_DIR); \
	fi
	@mkdir -p $(GTEST_BUILD_DIR)
	cd $(GTEST_BUILD_DIR) && cmake .. && $(MAKE)

samples: $(SAMPLES_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)/samples $^

liblogger: $(LOGGER_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $(BIN_DIR)/liblogger.so $^

fileprocessor: $(FILEPROCESSOR_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(BIN_DIR)/fileprocessor $^ -L$(BIN_DIR) -llogger

tests: gtest $(TEST_OBJS) $(LEGACY_CODE_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(RPATH_FLAG) -o $(BIN_DIR)/tests $(TEST_OBJS) $(LEGACY_CODE_OBJS) $(GTEST_LIB) $(GTEST_MAIN_LIB) -lpthread
	$(BIN_DIR)/tests

legacy_code: $(LEGACY_CODE_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(LEGACY_CODE_PATH)/legacy -o $(BIN_DIR)/legacy_code $^

# Ensure gtest is built legacy any test objects
$(TEST_OBJS): gtest

# Pattern rule for building objects
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)