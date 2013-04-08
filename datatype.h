#ifndef DATATYPE_H
#define DATATYPE_H
typedef int DataType;
// linklist
typedef struct Node{
    DataType data;
    struct Node *next;
}LNode, *PNode, *LinkList;

//seqlist
#define LISTSIZE 100

typedef struct {
    DataType item[LISTSIZE];
    int length;
}seqlist;

//dlinklist
typedef struct DLNode{
    DataType data;
    struct DLNode *prior;
    struct DLNode *next;

}DNode, *PDNode, *DLinkList;

//seqstack
#define STACKSIZE 100

typedef struct{
    DataType item[STACKSIZE];
    int top;
}seqstack;

//linkstack
typedef struct SNode{
    DataType data;
    struct SNode *next;
}SNode, *LinkStack;

#endif
