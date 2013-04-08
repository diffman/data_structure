#include "seqstack.h"
#include <stdio.h>
#include <stdlib.h>

int seqstack_init(seqstack *S)
{
    S->top = -1;
    return 1;
}

int seqstack_length(seqstack S)
{
    return S.top + 1;
}

int seqstack_is_empty(seqstack S)
{
    if(S.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int seqstack_push(seqstack *S, DataType x)
{
    if(S->top >= STACKSIZE -1)
    {
        printf("sequence stack is full, push failed.\r\n");
        return 0;
    }
    S->top ++;
    S->item[S->top] = x;

    return 1;
}

int seqstack_pop(seqstack *S, DataType *item)
{
    if(seqstack_is_empty(*S))
    {
        printf("sequece stack is empty, pop failed.\r\n");
        return 0;
    }
    *item = S->item[S->top];
    S->top --;

    return 1;
}

int seqstack_gettop(seqstack S, DataType *item)
{
    if(seqstack_is_empty(S))
    {
        printf("sequece stack is empty, get top failed.\r\n");
        return 0;
    }
    *item = S.item[S.top];

    return 1;
}

int seqstack_clear(seqstack *S)
{
    S->top = -1;
    return 1;
}

int seqstack_test()
{
    int data[6] = {1, 1, 3, 4, 5, 7};
    int i;
    DataType item;
    seqstack m_stack;
    seqstack_init(&m_stack);

    printf("*******************************\r\n");
    printf("Sequece Stack\r\n");
    printf("*******************************\r\n");
    //push 1,1,3,4,5,7
    printf("\n\n push 1, 1, 3, 4, 5, 7\r\n");
    for(i = 0; i < 6; i ++)
    {
        seqstack_push(&m_stack, data[i]);
    }

    printf("\n\n pop 7, 5, 4, 3..:\r\n");
    for(i = 0; i < 4; i++)
    {
        seqstack_pop(&m_stack, &item);
        printf("%d\r\n", item);
    }

    seqstack_clear(&m_stack);

    return 1;


}






