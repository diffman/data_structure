#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

//LinkList with head Node (or LinkList without head Node?)
int linklist_init(LinkList *h)
{
    *h = (LinkList)malloc(sizeof(LNode)); //create head Node .
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
    q->data = x;
    q->next = p->next;
    p->next = q;

    return 1;

}

int linklist_delete(LinkList h, int pos, DataType *item)
{
    PNode p = h;
    PNode q;
    int i = 0;
    while(p->next && i < pos - 1)
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

//void linklist_reverse(LinkList *h)
//{
//    PNode p = *h, q = NULL, r;

    //reverse every node.

//}

int linklist_test()
{
    int data[7] = {1, 1, 2, 3, 5, 7, 8};
    int i, length;
    LinkList m_linklist = NULL;
    DataType item;

    printf("Setup Linklist!\r\n");
    linklist_init(&m_linklist);
    for(i = 0; i < 7; i++)
    {
        if(!linklist_insert(m_linklist, i + 1, data[i]))
        {
            printf("\n error! \n");
            return 0;
        }
    }

    printf("\n\nTraverse:\r\n");
    linklist_traverse(m_linklist);

    printf("\n\nLength:\r\n");
    length = linklist_length(m_linklist);
    printf("\t%d", length);

    printf("\n\nInsert\"4 \":\r\n");
    if(!linklist_insert(m_linklist, 5, 4))
    {
        printf("\n error! \n");
        return 0;
    }
    linklist_traverse(m_linklist);

    printf("\n\nDelete:\r\n");
    if(linklist_delete(m_linklist, 7, &item))
    {
        printf("\n error! \n");
        return 0;
    }
    linklist_traverse(m_linklist);
    printf("%d\r\n", item);

    linklist_destroy(m_linklist);



}












