CC = g++

INC = ./

LFLAGS = $(shell wx-config --libs all)
CFLAGS = $(shell wx-config --cxxflags)

PROJ = SpySIM

SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

$(PROJ): $(OBJECTS)
	$(CC) $^ $(LFLAGS) -o $@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	rm $(OBJECTS) $(PROJ)