# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Target executable name
TARGET = $(BUILD_DIR)/Library_Management

# Find all .cpp files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Convert .cpp source files to .o object files in the build directory
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(BUILD_DIR) $(TARGET)

# Rule to create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link the object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile each .cpp file to a .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean
