PROG=main
SRCS=main.cc directorio.cc ruta.cc archivo.cc enlace.cc

CC=g++ -std=c++11
#CC=clang++ -std=c++11

CFLAGS:=-O3

OBJS=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS) nodo.h excepcion_arbol_ficheros.h
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cc %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(PROG) $(OBJS) core

dep:
	@makedepend -Y -- $(CFLAGS) -- $(SRCS) 2> /dev/null
	@rm -f Makefile.bak

# DO NOT DELETE
