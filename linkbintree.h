#include "datatype.h"

BiTreeLink linkbintree_create(char *nodes, int pos, int num);

void linkbintree_display(BiTreeLink root);

PBTNode linkbintree_insertright(PBTNode r, BTDataType x);

void linkbintree_releasetree(PBTNode *r);

void linkbintree_deleteright(PBTNode r);

void linkbintree_preorder(BiTreeLink r);

void linkbintree_nonpreorder(BiTreeLink r);

void linkbintree_inorder(BiTreeLink r);

void linkbintree_noninorder(BiTreeLink r);

void linkbintree_postorder(BiTreeLink r);

void linkbintree_nonpostorder(BiTreeLink r);

int linkbintree_count(BiTreeLink r);

int linkbintree_depth(BiTreeLink r);

PBTNode linkbintree_findnode(BiTreeLink r, BTDataType x);

int linkbintree_leafcount(BiTreeLink r);

int linkbintree_test();






