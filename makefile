CC=clang++
CFLAGS=-Wall -std=c++0x
LDFLAGS=-lboost_date_time-mt
SOURCES=main.cpp SecurityMaster.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
