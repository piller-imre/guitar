CC = g++

# Debug
CFLAGS = -Iinclude -I../src -g -O2 -Wall
LDFLAGS = -lGL -lGLU -lglut -lSOIL 

SOURCES = \
	src/DrawScene.cpp \
    src/model.cpp \
    src/beadandokesz.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = guitar.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)
