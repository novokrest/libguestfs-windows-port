CC = gcc
CFLAGS = 

LIBRARY = world
LIB_HEADERS = world.h
LIB_SOURCES = helloworld.c byebyeworld.c
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)

EXEC_SOURCES = main.c
EXEC_OBJECTS = $(EXEC_SOURCES:.c=.o)
EXECUTABLE = test

.PHONY: all clean

all: $(LIBRARY) $(EXECUTABLE)

$(EXECUTABLE): $(LIBRARY)
	gcc -L. -Wl,-rpath=. -Wall -o test main.c -l$(LIBRARY)

$(LIBRARY): $(LIB_OBJECTS)
	$(CC) -shared -o lib$(LIBRARY).so $(LIB_OBJECTS)

#$(EXECUTABLE): $(EXEC_OBJECTS) $(LIBRARY)

%.o: %.c $(LIB_HEADERS)
	$(CC) -c -Wall -Werror -fPIC -o $@ $<

clean:
	rm -f *.o
