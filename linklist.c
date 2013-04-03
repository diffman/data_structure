#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

//LinkList with head point
int linklist_init(LinkList *h)
{
    *h = (LinkList)malloc(sizeof(LNode));
    if(!h)
    {
        printf("Init Linklist error!\r\n");
        return 0;
    }

    (*h)->next = NULL;
    return 1;
}

int linklist_length(LinkList h)
{
    int total = 0;
    PNode p = h->next;

    while(p)
    {
        total ++;
        p = p->next;
    }
    return total;
}

int linklist_is_empty(LinkList h)
{
    if (h->next)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int linklist_insert(LinkList h, int pos, DataType x)
{
    PNode p = h;
    PNode q;
    int i = 0;
    while(p && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if(!p || i > pos -1)
    {
        printf("unable to insert, the position is error! \r\n");
        return 0;
    }
    q = (PNode)malloc(sizeof(LNode));
    if(!q)
    {
        printf("unable to create new Node\r\n");
        return 0;
    }
    q->next = p->next;
    p->next = q;

    return 1;

}

int linklist_delete(LinkList h, int pos, DataType *item)
{
    PNode p = h;
    PNode q;
    int i = 0;
    while(p->next && i > pos - 1)
    {
        p = p -> next;
        i ++;
    }

    if(!p->next || i > pos -1)
    {
        printf("unable to delete, the position is error! \r\n");
        return 0;
    }

    q = p->next;
    p->next = q->next;
    *item = q->data;
    free(q);

    return 1;

}

//return adress of Node
int linklist_find(LinkList h, DataType item)
{
    int pos = 0;
    PNode p;
    p = h->next;
    while(p && p->data != item)   //question: p->data != item is right to struct type?
    {
        pos ++;
        p = p->next;
    }
    if(!p)
    {
        return 0;
    }

    else
    {
        return pos;
    }

}

int linklist_get_elem(LinkList h, int pos, DataType *item)
{
    int i = 0;
    LinkList p;
    p = h->next;
    while(p && i < pos - 1)
    {
        i++;
        p = p->next;
    }

    if (!p || i > pos - 1)
    {
        printf("unable to get element, the position is error! \r\n");
    }

    *item = p->data;
    return 1;

}

void linklist_destroy(LinkList h)
{
    LinkList p;
    p = h->next;
    while(h)
    {
        p = h;
        h = h -> next;
        free(p);
    }

}

void linklist_traverse(LinkList h)
{
    PNode p;
    p = h->next;
    while(p)
    {
        printf("%d \t", p->data);
        p = p->next;
    }

    printf("\n");
}







