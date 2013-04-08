#include "datatype.h"

int linklist_init(LinkList *h);

int linklist_length(LinkList h);

int linklist_is_empty(LinkList h);

int linklist_insert(LinkList h, int pos, DataType x);

int linklist_delete(LinkList h, int pos, DataType *item);

int linklist_find(LinkList h, DataType item);

int linklist_get_elem(LinkList h, int pos, DataType *item);

void linklist_destroy(LinkList h);

void linklist_traverse(LinkList h);

void linklist_reverse(LinkList *h);

int linklist_test();

