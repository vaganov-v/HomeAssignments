CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++17
SRC = main.cpp Transformer.cpp Gun.cpp Alliance.cpp Autobot.cpp Decepticon.cpp Pretender.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = transformers

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
