CXX = g++
CXXFLAGS = -Wall -Wextra
SRC = main.cpp rpn_calculator.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = rpn_calc

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
