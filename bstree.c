#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

BSTNode *BSTSearch(BSTree r, BSTDataType x)
{
    BSTNode *p;
    p = r;

    if(r == NULL)
    {
        return NULL;
    }
    while(p != NULL)
    {
        if(p->data.key == x.key)
        {
            return p;
        }
        if(p->data.key < x.key)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return NULL;
}

void BSTInsert(BSTree *r, BSTDataType x)
{
    BSTNode *p, *q = NULL;
    p = *r;

    while(p != NULL)
    {
        q = p;
        if(p->data.key == x.key)
        {
            return;
        }
        if(p->data.key < x.key)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }

    p = (BSTNode *)malloc(sizeof(BSTNode));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    if(q == NULL)
    {
        *r = p;
        return;
    }
    if(q->data.key > x.key)
    {
        q->left = p;
    }
    else
    {
        q->right = p;
    }
}

void CreateBSTree(BSTree *r, BSTDataType item[], int n)
{
    int i;
    for(i = 0; i < n; i ++)
    {
        BSTInsert(r, item[i]);
    }
}

void BSTDelete(BSTree *r, BSTDataType x)
{
    BSTNode *p, *q = NULL, *s;  //q record p's pioneer.
    p = *r;

    while(p != NULL && p->data.key != x.key)
    {
        q = p;
        if(p->data.key<x.key)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    if (p == NULL) //can't find x.
    {
        return;
    }

    s = p; //delete node.
    if(s->left && s->right)  //find delete pioneer node. and p point to it.
    {
        q = s;
        p = s->left;
        while(p->right != NULL)
        {
            q = p;
            p = p->right;
        }

        if(p != s)
        {
            s->data = p->data;// delete node = it's pre node data.
        }
    }

    // delete pioneer node or delete node.
    s = p->left ? p->left:p->right;
    if(!q) //q is p's pioneer. if !q , p is root node .
    {
        *r = s;
    }
    else
    {
        if(q->left == p)
        {
            q->left = s;
        }
        else
        {
            q->right = s;
        }

        free(p);
    }
}

void DisplayBST(BSTree r)
{
    if(!r)
    {
        return;
    }
    if(r->left != NULL)
    {
        DisplayBST(r->left);
    }
    printf("%d \t", r->data.key);
    if(r->right != NULL)
    {
        DisplayBST(r->right);
    }
}

int BST_test()
{
    BSTree root = NULL;
    BSTNode *p;
    BSTDataType item[] = {5, 9, 4, 1, 15, 8, 2};
    BSTDataType x = {10};

    printf("*******************************\r\n");
    printf("BST tree:\r\n");
    printf("*******************************\r\n");

    printf("creat tree item[](5 9 4 1 15 8 2):\r\n");
    CreateBSTree(&root, item, 7);
    DisplayBST(root);
    printf("\n");
    printf("find item[2]:\r\n");
    p = BSTSearch(root, item[2]);
    printf("%d \n", p->data.key);
    printf("insert (10):\r\n");
    BSTInsert(&root, x);
    DisplayBST(root);
    printf("\n");
    printf("delete item[3]:\r\n");
    BSTDelete(&root, item[3]);
    DisplayBST(root);
    printf("\n");
    printf("delete item[1]:\r\n");
    BSTDelete(&root, item[1]);
    DisplayBST(root);
    printf("\n");

    return 0;

}





