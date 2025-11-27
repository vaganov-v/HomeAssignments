PROJECT = transformers
LIBPROJECT = $(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
A = ar
AFLAGS = rsv
CXXFLAGS = -Isrc -std=c++17 -Wall -Wextra -Werror -Wpedantic -g -fPIC

DEPS = $(wildcard src/*.h)
OBJ = src/Transformer.o src/Gun.o src/Alliance.o \
      src/Autobot.o src/Decepticon.o src/Pretender.o

TEST_OBJ = tests/TransformerTests.o

LDXXFLAGS = $(CXXFLAGS) -L. -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

.PHONY: all test clean cleanall

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^

$(TESTPROJECT): $(LIBPROJECT) $(TEST_OBJ)
	$(CXX) -o $@ $(TEST_OBJ) $(LDGTESTFLAGS)

test: $(TESTPROJECT)

all: $(LIBPROJECT)

clean:
	rm -f src/*.o tests/*.o

cleanall: clean
	rm -f $(LIBPROJECT) $(TESTPROJECT)
