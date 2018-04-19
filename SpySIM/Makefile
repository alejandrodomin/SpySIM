CC = g++

INC = ./

LFLAGS = $(shell wx-config --libs all)
CFLAGS = $(shell wx-config --cxxflags) -std=c++11

DEBUG = -g

PROJ = SpySIM

SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

$(PROJ): $(OBJECTS)
	$(CC) $^ $(LFLAGS) -o $@

%.o: %.cpp %.h
	$(CC) $(DEBUG) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	rm $(OBJECTS) $(PROJ)
