CXX := g++
CXXFLAGS := -Wall -Wextra -O2
TARGET := main
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
