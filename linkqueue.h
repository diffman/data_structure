#include "datatype.h"

int linkqueue_init(LinkQueue *Q);

int linkqueue_is_empty(LinkQueue Q);

int linkqueue_enqueue(LinkQueue *Q, DataType x);

int linkqueue_dequeue(LinkQueue *Q, DataType *item);

int linkqueue_gethead(LinkQueue Q, DataType *item);

int linkqueue_destroy(LinkQueue *Q);

int linkqueue_test();

