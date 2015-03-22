CC = gcc
CFLAGS := -I. `pkg-config --cflags libprotobuf-c`
LIBS := `pkg-config --libs libprotobuf-c`
SOURCES = simple_test.c simple.pb-c.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = simple.exe

.PHONY: all clean

all: proto $(EXECUTABLE)

proto:
	protoc-c --c_out=. simple.proto

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f *.o
