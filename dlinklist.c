#include "dlinklist.h"
#include <stdio.h>
#include <stdlib.h>

DLinkList dlinklist_init()
{
    DLinkList h;
    h = (DLinkList)malloc(sizeof(DLNode));//create head node
    if(!h)
    {
        printf("Init Dlinklist error ! \r\n");
        return 0;
    }
    h->next = *h;
    h->prior = *h;
    return h;
}

int dlinklist_insert(DLinkList h, int pos, DataType x)
{
    PDNode p = h->next, q;
    int i = 0;
    while(p != h && i < pos -1)
    {
        p = p->next;
        i ++;
    }

    if(p = h || i > pos - 1)
    {
        printf("error\r\n");
        return 0;
    }

    q = (PDNode)malloc(sizeof(DNode));
    if(!q)
    {
        printf("error\r\n");
        return 0;
    }

    q->data = x;
    q->prior = p->prior;
    p->prior->next = q;
    q->next = p;
    p->prior = q;
    return 1;
}

int dlinklist_delete(DLinkList h, int pos, DataType *item)
{
    PDNode p = h->next;
    int i = 1;
    while(p->next != h && i < pos)
    {
        p = p->next;
        i ++;
    }
    if(p->next == h || i > pos)
    {
        printf("delete position error\r\n");
        return 0;
    }
    *item = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
}







