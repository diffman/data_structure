#include "datatype.h"

int HashCollision(int d);

int HashFunc(int key);

int HashSearch(HashTable ht, HASHDataType x);

int HashInsert(HashTable ht, HASHDataType x);

void CreateHash(HashTable ht, HASHDataType item[],int n);

int HashDelete(HashTable ht, HASHDataType x);

void DisplayHash(HashTable ht);

int Hash_test();
