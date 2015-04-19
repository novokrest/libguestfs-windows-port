CC = gcc
CFLAGS = -Wall
CPPFLAGS =-I.
LDFLAGS = 
LIBS = -lrt
SOURCES = \
  main.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = 
EXEC = test

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -f *.o *~

.PHONY: all clean
