CXX = clang++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++03 -g

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.d)

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
