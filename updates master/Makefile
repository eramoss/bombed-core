CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC_DIR = src
BUILD_DIR = build
TARGET_MAIN = bombed_core
TEST_DIR = tests

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean test

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@$(TARGET_MAIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: 
	mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/tests $(TEST_DIR)/main.cpp

clean:
	rm -rf $(BUILD_DIR)

