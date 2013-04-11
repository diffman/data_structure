#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

int linkqueue_init(LinkQueue *Q)
{
    PQNode p;
    p = (PQNode)malloc(sizeof(LQNode));
    if(!p)
    {
        printf("create head qnode error.\r\n");
        return 0;
    }
    Q->front = Q->rear = p;

    Q->front->next = NULL;
}

int linkqueue_is_empty(LinkQueue Q)
{
    if(Q.front == Q.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int linkqueue_enqueue(LinkQueue *Q, DataType x)
{
    PQNode p;
    p = (PQNode)malloc(sizeof(LQNode));
    if(!p)
    {
        printf("create qnode error.\r\n");
        return 0;
    }
    p->data = x;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;

    return 1;
}

int linkqueue_dequeue(LinkQueue *Q, DataType *item)
{
    PNode p;
    if(linkqueue_is_empty(*Q))
    {
        printf("empty,dequeue error.\r\n");
        return 0;
    }
    p = Q->front->next;
    *item = p->data;
    Q->front->next = p->next;
    free(p);
    if(Q->rear == p)
    {
        Q->rear = Q->front;
    }
    return 1;
}

int linkqueue_gethead(LinkQueue Q, DataType *item)
{
    PNode p;
    if(linkqueue_is_empty(Q))
    {
        printf("empty,get head error.\r\n");
        return 0;
    }
    p = Q.front->next;
    *item = p->data;

    return 1;
}

int linkqueue_destroy(LinkQueue *Q)
{
    while(Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }

    return 1;
}

int linkqueue_test()
{
    int i;
    int data[7] = { 1, 1, 2, 3, 5, 6, 8};
    DataType item;
    LinkQueue m_linkqueue;
    linkqueue_init(&m_linkqueue);
    printf("*******************************\r\n");
    printf("Sequece Queue\r\n");
    printf("*******************************\r\n");
    printf("enqueue 1,1,2,3,5,6,8:\r\n");
    for(i = 0; i < 7; i++)
    {
        if(!linkqueue_enqueue(&m_linkqueue, data[i]))
        {
            printf("enqueue error.\r\n");
            return 0;
        }
    }

    printf("\n\nDequeue All:\r\n");
    for(i = 0; i < 7; i++)
    {
        if(!linkqueue_dequeue(&m_linkqueue, &item))
        {
            printf("error.\r\n");
            return 0;
        }
        printf("%d\r\n", item);
    }

    linkqueue_destroy(&m_linkqueue);

    return 1;

}







