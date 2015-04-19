SOURCES = simple.ml
EXECUTABLE = simple.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	ocamlopt -o $@ $^

clean:
	rm -f *.cmi *.cmx *.o

.PHONY: all clean
