#ifndef DATATYPE_H
#define DATATYPE_H
typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node *next;
}LNode, *PNode, *LinkList;

#define LISTSIZE 100

typedef struct {
    DataType item[LISTSIZE];
    int length;
}seqlist;

typedef struct DLNode{
    DataType data;
    struct DLNode *prior;
    struct DLNode *next;

}DNode, *PDNode, *DLinkList;

#endif
