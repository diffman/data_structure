#include <stdio.h>
#include "seqlist.h"
#include "linklist.h"
#include "seqstack.h"
#include "linkstack.h"

int main(int argc ,char *argv[])
{
    //int res = seqlist_test();
    //linklist
    int res = linklist_test();
    //seqstack
    seqstack_test();
    //linkstack
    linkstack_test();
    return res;

}
