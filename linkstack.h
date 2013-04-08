#include "datatype.h"

int linkstack_init(LinkStack *top);

int linkstack_is_empty(LinkStack top);

int linkstack_push(LinkStack top, DataType x);

int linkstack_pop(LinkStack top, DataType *item);

int linkstack_gettop(LinkStack top, DataType *item);

int linkstack_destroy(LinkStack top);

int linkstack_test();
