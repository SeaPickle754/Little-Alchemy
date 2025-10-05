# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -g -Wall

# Output
TARGET := bin/Debug/little-alchemy

# Source directories
SRC_DIR := .
UI_DIR := ui

# Gather source files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(UI_DIR)/*.cpp)

# Object files
OBJECTS := $(SOURCES:.cpp=.o)

# SFML libraries
SFML_LIBS := -lsfml-graphics -lsfml-network -lsfml-window -lsfml-audio -lsfml-system

# Default target# Default target
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
# Clean build artifacts
clean:
	rm -f $(SRC_DIR)/*.o $(UI_DIR)/*.o $(TARGET)
