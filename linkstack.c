#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

int linkstack_init(LinkStack *top)
{
    *top = (LinkStack)malloc(sizeof(SNode));
    if(*top == NULL)
    {
        printf("init error!\r\n");
        return 0;
    }

    (*top)->next = NULL;
    return 1;
}

int linkstack_is_empty(LinkStack top)
{
    if(top->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int linkstack_push(LinkStack top, DataType x)
{
    SNode *p;
    p = (SNode *)malloc(sizeof(SNode));
    if(!p)
    {
        printf("push error!\r\n");
        return 0;
    }
    p->data = x;
    p->next = top->next;
    top->next = p;

    return 1;
}

int linkstack_pop(LinkStack top, DataType *item)
{
    SNode *p;
    if(linkstack_is_empty(top))
    {
        printf("linklist is empty, pop faild.\r\n");
        return 0;
    }
    p = top->next;
    top->next = p->next;
    *item = p->data;
    free(p);
    return 1;
}

int linkstack_gettop(LinkStack top, DataType *item)
{
    SNode *p;
    if(linkstack_is_empty(top))
    {
        printf("linklist is empty, get top faild.\r\n");
        return 0;
    }

    p = top->next;
    *item = p->data;
    return 1;
}

int linkstack_destroy(LinkStack top)
{
    SNode *p;
    while(top)
    {
        p = top;
        top = top->next;
        free(p);
    }

    return 1;
}

int linkstack_test()
{
    LinkStack m_linkstack;
    int data[7] = {1, 1, 3, 4, 5, 7, 8};
    DataType item;
    int i;


    printf("*******************************\r\n");
    printf("Sequece Stack\r\n");
    printf("*******************************\r\n");
    linkstack_init(&m_linkstack);
    printf("Push 1, 1, 3, 4, 5, 7, 8\r\n");
    for(i = 0; i < 7; i++)
    {
        if(!linkstack_push(m_linkstack, data[i]))
        {
            printf("error!\r\n");
            return 0;
        }
    }
    printf("pop 8, 7, 5, 4:\r\n");
    for(i = 0; i < 4; i++)
    {
        if(!linkstack_pop(m_linkstack, &item))
        {
            printf("error!\r\n");
            return 0;
        }
        printf("%d\r\n", item);
    }

    linkstack_destroy(m_linkstack);
    return 1;

}








