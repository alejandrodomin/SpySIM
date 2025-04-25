CC = g++

INC = ./lib

LFLAGS = $(shell wx-config --libs all)
CFLAGS = $(shell wx-config --cxxflags) -std=c++11

DEBUG = -g

PROJ = SpySIM

SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(SOURCES:src/%.cpp=build/%.o)

$(PROJ): $(OBJECTS)
	$(CC) $^ $(LFLAGS) -o $@

build/%.o: src/%.cpp
	@mkdir -p build
	$(CC) $(DEBUG) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	-rm -rf build/ $(PROJ)
