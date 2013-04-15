#compiler
CC = gcc

#flag
#CFLAGS = -Wall -ansi -g
CFLAGS = -g

#objects
OBJS = data_structure.o seqlist.o linklist.o seqstack.o linkstack.o seqqueue.o linkqueue.o linkbintree.o bstree.o

INSTALL_PATH = ./

all: data_structure

data_structure: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

data_structure.o: data_structure.c seqlist.h datatype.h seqstack.h linkstack.h seqqueue.h linkqueue.h linkbintree.c linkbintree.h bstree.h
	$(CC) $(CFLAGS) -c -o $@ $<

seqlist.o: seqlist.c seqlist.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

linklist.o: linklist.c linklist.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

seqstack.o: seqstack.c seqstack.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

linkstack.o: linkstack.c linkstack.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

seqqueue.o: seqqueue.c seqqueue.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

linkqueue.o: linkqueue.c linkqueue.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<

linkbintree.o: linkbintree.c linkbintree.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<
bstree.o: bstree.c bstree.h datatype.h
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	-rm -f *.o *.ko .*.cmd .*.flags *.mod.c data_structure
