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

//seqqueue
#define QUEUESIZE 100

typedef struct{
    DataType items[QUEUESIZE];
    int front, rear;
}seqqueue;

//linkqueue
typedef struct QNode{
    DataType data;
    struct QNode *next;
}LQNode, *PQNode;

typedef struct{
    PQNode front, rear;
}LinkQueue;

typedef char BTDataType;
//linkBintree
typedef struct BTNode{
    BTDataType data;
    struct BTNode *left;
    struct BTNode *right;
}BTNode, *PBTNode, *BiTreeLink;

//link BThrtree
typedef struct TBNode{
    BTDataType data;
    int lthread,rthread;
    struct TBNode *left, *right;
}TBNode, *PTBNode, *TBLink;

//BSTree 二叉排序树
typedef int KeyType;
typedef struct{
    KeyType key;
}BSTDataType;

typedef struct BSTNode{
    BSTDataType data;
    struct BSTNode *left, *right;
}BSTNode, *BSTree;

#endif







