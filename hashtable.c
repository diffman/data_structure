#include "hashtable.h"
#include <stdio.h>

//return address.
int HashCollision(int d)
{
    return (d + 1) % HASHSIZE;
}

int HashFunc(int key)
{
    return key % HASHSIZE;
}

int HashSearch(HashTable ht, HASHDataType x)
{
    int addr;
    addr = HashFunc(x.key);
    while(ht[addr].data.key != NULL && ht[addr].data.key != x.key)
    {
        addr = HashCollision(addr);
    }

    if(ht[addr].data.key == x.key)
    {
        return addr;
    }
    else
    {
        return -addr;
    }
}

int HashInsert(HashTable ht, HASHDataType x)
{
    int addr;
    addr = HashSearch(ht, x);

    if(addr >= 0)
    {
        return 0;
    }
    ht[-addr].data = x;
    ht[-addr].times = 1;

    return 1;
}

void CreateHash(HashTable ht, HASHDataType item[],int n)
{
    int i;
    for (i = 0; i < HASHSIZE; i++)
    {
        ht[i].data.key = NULL;
        ht[i].times = 0;
    }

    for(i = 0; i < n; i++)
    {
        HashInsert(ht, item[i]);
    }
}

int HashDelete(HashTable ht, HASHDataType x)
{
    int addr;
    addr = HashSearch(ht, x);
    if(addr >= 0)
    {
        ht[addr].data.key = DELFLAG;
        return 1;
    }
    return 0;
}

void DisplayHash(HashTable ht)
{
    int i;
    printf("\n HashTable\n Hash Addr:\t");
    for(i = 0; i < HASHSIZE; i ++)
    {
        printf("%d \t", i);
    }
    printf("\n key:\t");
    for(i = 0; i < HASHSIZE; i ++)
    {
        if(ht[i].data.key != NULL)
        {
            printf("%d \t", ht[i].data.key);
        }
        else
            printf("\t");
    }
    printf("\n");
}

int Hash_test()
{
    int addr;
    HASHDataType x;
    HASHDataType item[6] = {15, 59, 22, 34, 7, 78};
    HashTable ht;

    printf("*******************************\r\n");
    printf("Hash Table:\r\n");
    printf("*******************************\r\n");

    CreateHash(ht, item, 6);
    DisplayHash(ht);

    x.key = 7;
    addr = HashSearch(ht, x);
    if(addr >= 0)
    {
        printf("the Hash Addr of item(%d) is [%d]\n", x.key, addr);
    }
    else
    {
        printf("No item (%d) in HashTable.\n", x.key);
    }
    HashDelete(ht, x);
    DisplayHash(ht);

    x.key = 25;
    HashInsert(ht, x);
    DisplayHash(ht);
    return 0;
}







