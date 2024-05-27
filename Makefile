CXX = clang++
ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
CXXFLAGS = -I$(ROOT_DIR) -Wall -Wextra -pedantic -std=c++17 -fsanitize=address,undefined -g

SRC_DIRS := . UI DataType DataAccess Service Util

SOURCES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(SOURCES:.cpp=.d)

EXEC = e-commerce

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(EXEC) $(OBJECTS) $(DEPS)

.PHONY: all clean
