#compiler
CC = gcc

#flag
#CFLAGS = -Wall -ansi -g
CFLAGS = -g

#objects
OBJS = data_structure.o seqlist.o linklist.o seqstack.o linkstack.o

INSTALL_PATH = ./

all: data_structure

data_structure: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

data_structure.o: data_structure.c seqlist.h datatype.h seqstack.h linkstack.h
	$(CC) $(CFLAGS) -c -o $@ $<

seqlist.o: seqlist.c seqlist.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

linklist.o: linklist.c linklist.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

seqstack.o: seqstack.c seqstack.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

linkstack.o: linkstack.c linkstack.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -f *.o *.ko .*.cmd .*.flags *.mod.c data_structure
