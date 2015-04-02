top_srcdir = ../../

CC = gcc
CPPFLAGS = -I. -I$(top_srcdir)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

all: gnulib

gnulib: $(OBJECTS)
	ar rcs $@.a $^

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o

.PHONY: all clean
