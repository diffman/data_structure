#include "seqqueue.h"
#include <stdio.h>
#include <stdlib.h>

int seqqueue_init(seqqueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return 1;
}

int seqqueue_is_empty(seqqueue Q)
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

int seqqueue_length(seqqueue Q)
{
    return(Q.rear - Q.front +QUEUESIZE)%QUEUESIZE;
}

int seqqueue_enqueue(seqqueue *Q, DataType e)
{
    if((Q->rear + 1) % QUEUESIZE == Q->front)
    {
        printf("queue is full, enqueue faild.\r\n");
        return 0;
    }

    Q->items[Q->rear] = e;
    Q->rear = (Q->rear + 1) % QUEUESIZE;
    return 1;
}

int seqqueue_dequeue(seqqueue *Q, DataType *item)
{
    if(seqqueue_is_empty(*Q))
    {
        printf("queue is empty,dequeue faild.\r\n");
        return 0;
    }
    *item = Q->items[Q->front];
    Q->front = (Q->front + 1) % QUEUESIZE;
    return 1;
}

int seqqueue_gethead(seqqueue Q, DataType *item)
{
    if(seqqueue_is_empty(Q))
    {
        printf("queue is empty,get head faild.\r\n");
        return 0;
    }

    *item = Q.items[Q.front];
    return 1;
}

int seqqueue_traverse(seqqueue Q)
{
    int pos;
    pos = Q.front;

    while((pos + 1) % QUEUESIZE <= Q.rear)
    {
        printf("%d\t", Q.items[pos]);
        pos ++;
    }
    printf("\n");
    return 1;
}

int seqqueue_test()
{
    int i;
    DataType item;
    int data[7] = {1, 1, 2, 3, 5, 6, 8};
    seqqueue m_seqqueue;
    seqqueue_init(&m_seqqueue);

    printf("*******************************\r\n");
    printf("Sequece Queue\r\n");
    printf("*******************************\r\n");
    printf("enqueue 1,1,2,3,5,6,8:\r\n");
    for(i = 0; i < 7; i ++)
    {
        if(!seqqueue_enqueue(&m_seqqueue, data[i]))
        {
            printf("error.\r\n");
            return 0;
        }

    }

    printf("\n\nDequeue All:\r\n");
    for(i = 0; i < 7; i++)
    {
        if(!seqqueue_dequeue(&m_seqqueue, &item))
        {
            printf("error.\r\n");
            return 0;
        }
        printf("%d\r\n", item);
    }

    seqqueue_enqueue(&m_seqqueue, 5);
    seqqueue_gethead(m_seqqueue, &item);
    printf("get head %d\r\n", item);

    return 1;


}












