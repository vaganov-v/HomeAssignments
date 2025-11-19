CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = main.cpp file_utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = reverse_file

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
