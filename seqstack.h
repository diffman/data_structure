#include "datatype.h"

int seqstack_init(seqstack *S);

int seqstack_length(seqstack S);

int seqstack_push(seqstack *S, DataType x);

int seqstack_pop(seqstack *S, DataType *item);

int seqstack_gettop(seqstack S, DataType *item);

int seqstack_is_empty(seqstack S);

int seqstack_clear(seqstack *S);

int seqstack_test();


// need not destroy in seqstack.
//int seqstack_destroy(seqstack *S);
