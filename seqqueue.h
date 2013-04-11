#include "datatype.h"

int seqqueue_init(seqqueue *Q);

int seqqueue_is_empty(seqqueue Q);

int seqqueue_length(seqqueue Q);

int seqqueue_enqueue(seqqueue *Q, DataType e);

int seqqueue_dequeue(seqqueue *Q, DataType *item);

int seqqueue_gethead(seqqueue Q, DataType *item);

int seqqueue_traverse(seqqueue Q);

int seqqueue_test();
