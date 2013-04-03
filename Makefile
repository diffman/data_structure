#compiler
CC = gcc

#flag
#CFLAGS = -Wall -ansi -g
CFLAGS = -g

#objects
OBJS = data_structure.o seqlist.o

INSTALL_PATH = ./

all: data_structure

data_structure: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

data_structure.o: data_structure.c seqlist.h
	$(CC) $(CFLAGS) -c -o $@ $<

seqlist.o: seqlist.c seqlist.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -f *.o *.ko .*.cmd .*.flags *.mod.c data_structure
