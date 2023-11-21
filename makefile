# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Debug flags
DEBUG_FLAGS = -g

# Optimized flags
OPTIMIZE_FLAGS = -O3

# Source files
SRC_Q1 = Q1.cpp
SRC_Q2 = Q2.cpp
SRC_Q3 = Q3.cpp
SRC_Q4 = Q4.cpp

# Output binaries
DEBUG_BIN_Q1 = debug_binary_q1
OPTIMIZE_BIN_Q1 = optimize_binary_q1
DEBUG_BIN_Q2 = debug_binary_q2
OPTIMIZE_BIN_Q2 = optimize_binary_q2
DEBUG_BIN_Q3 = debug_binary_q3
OPTIMIZE_BIN_Q3 = optimize_binary_q3
DEBUG_BIN_Q4 = debug_binary_q4
OPTIMIZE_BIN_Q4 = optimize_binary_q4

# Default target
all: debug optimize

# Debug targets
debug: debug_q1 debug_q2 debug_q3 debug_q4

debug_q1: $(SRC_Q1)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(SRC_Q1) -o $(DEBUG_BIN_Q1)

debug_q2: $(SRC_Q2)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(SRC_Q2) -o $(DEBUG_BIN_Q2)

debug_q3: $(SRC_Q3)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(SRC_Q3) -o $(DEBUG_BIN_Q3)

debug_q4: $(SRC_Q4)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(SRC_Q4) -o $(DEBUG_BIN_Q4)

# Optimized targets
optimize: optimize_q1 optimize_q2 optimize_q3 optimize_q4

optimize_q1: $(SRC_Q1)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE_FLAGS) $(SRC_Q1) -o $(OPTIMIZE_BIN_Q1)

optimize_q2: $(SRC_Q2)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE_FLAGS) $(SRC_Q2) -o $(OPTIMIZE_BIN_Q2)

optimize_q3: $(SRC_Q3)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE_FLAGS) $(SRC_Q3) -o $(OPTIMIZE_BIN_Q3)

optimize_q4: $(SRC_Q4)
	$(CXX) $(CXXFLAGS) $(OPTIMIZE_FLAGS) $(SRC_Q4) -o $(OPTIMIZE_BIN_Q4)

# Clean target
clean:
	rm -f $(DEBUG_BIN_Q1) $(OPTIMIZE_BIN_Q1) $(DEBUG_BIN_Q2) $(OPTIMIZE_BIN_Q2) $(DEBUG_BIN_Q3) $(OPTIMIZE_BIN_Q3) $(DEBUG_BIN_Q4) $(OPTIMIZE_BIN_Q4)

.PHONY: all debug optimize clean
