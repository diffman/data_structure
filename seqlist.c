#include <stdio.h>
#include "seqlist.h"

int list_init(seqlist *L)
{
    L->length = 0;
    return 1;
}

int list_get_length(seqlist L)
{
    return L.length;
}

int list_is_empty(seqlist L)
{
    if(L.length <= 0)
        return 1;
    else
        return 0;
}

int list_insert(seqlist *L, int pos, DataType item)
{
    int i;

    if(L->length >= LISTSIZE)
    {
        printf("Sequence list is full,can't insert!\r\n");
        return 0;
    }
    if(pos <= 0 || pos > L->length+1)
    {
        printf("Position is not right, should be [1, length + 1]\r\n");
        return 0;
    }

    for(i = L->length - 1; i >=  pos -1; i--)
    {
        L->item[i + 1] = L->item[i];
    }
    L->item[pos -1] = item;
    L->length ++;
    return 1;
}

int list_delete(seqlist *L, int pos, DataType *item)
{
    int i;
    if(list_is_empty(*L))
    {
        printf("Sequence list is empty,can't delete\r\n");
        return 0;
    }
    if(pos <= 0 || pos > L->length)
    {
        printf("Position is not right, shold be [1, length]\r\n");
        return 0;
    }

    for(i = pos -1; i < L->length -1; i++)
    {
        L->item[i] = L->item[i + 1];
    }
    L->length --;
    return 1;
}

int list_find(seqlist L, DataType item)
{
    int pos = 0;
    if(list_is_empty(L))
    {
        printf("Sequence list is empty,can't find.\r\n");
        return 0;
    }
    while(pos < L.length && L.item[pos] != item)
    {
        pos ++;
    }
    if(pos < L.length)
    {
        return pos + 1;
    }
    else
    {
        return 0;
    }
}

int list_get_elem(seqlist L, int pos, DataType *item)
{
    if(list_is_empty(L))
    {
        printf("Sequence list is empty,can't get element.\r\n");
        return 0;
    }
    if(pos <= 0 || pos > L.length)
    {
        printf("Position is not right, shold be [1, length]\r\n");
        return 0;
    }
    *item = L.item[pos - 1];
    return 1;
}

int list_traverse(seqlist L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d\t", L.item[i]);
    }
    printf("\n");
    return 1;
}

int seqlist_test()
{
    seqlist my_seqlist;
    int i;
    int data[7] = {0, 1, 1, 2, 3, 5, 8};
    DataType item;

    printf("*******************************\r\n");
    printf("Sequence List\r\n");
    printf("*******************************\r\n");

    printf("\n\n Setup Sequence List\n\n");
    list_init(&my_seqlist);
    for (i = 0; i < 7; i++)
    {
        if(!list_insert(&my_seqlist, i+1, data[i]))
        {
            printf("\n error! \n");
            return 0;
        }
    }
    printf("\n\n Data Elements before delete\n");
    list_traverse(my_seqlist);

    if(!list_delete(&my_seqlist, 6, &item))
    {
        printf("\n error! \n");
        return 0;
    }

    printf("\n\n Data Elements after delete\n");
    list_traverse(my_seqlist);
    return 1;
}














