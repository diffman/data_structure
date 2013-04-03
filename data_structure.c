#include <stdio.h>
#include "seqlist.h"

int main(int argc ,char *argv[])
{
    seqlist my_seqlist;
    int i;
    int data[7] = {0, 1, 1, 2, 3, 5, 8};
    DataType item;

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
