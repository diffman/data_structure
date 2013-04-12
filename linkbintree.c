#include "linkbintree.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

BiTreeLink linkbintree_create(char *nodes, int pos, int num)
{
    PBTNode p;
    if(nodes[pos] == ' ' || pos > num)
    {
        return NULL;
    }

    p = (PBTNode)malloc(sizeof(BTNode));
    if(!p)
    {
        printf("creat btnode error.\r\n");
        return 0;
    }
    p->data = nodes[pos];
    p->left = linkbintree_create(nodes, 2*pos, num);
    p->right = linkbintree_create(nodes, 2*pos + 1, num);

    return p;
}

void linkbintree_display(BiTreeLink root)
{
    PBTNode queue[MAXSIZE];
    int front, rear;
    PBTNode p;
    if(root == NULL)
    {
        return;
    }
    queue[0] = root;
    front = 0;
    rear = 1;
    while(front < rear)
    {
        p = queue[front];
        front = (front + 1) % MAXSIZE;
        if(p == NULL)
        {
            printf("( )");
        }
        else
        {
            printf("(%c)", p->data);
        }

        if(p != NULL)
        {
            queue[rear] = p->left;
            rear = (rear + 1) % MAXSIZE;
            queue[rear] = p->right;
            rear = (rear + 1) % MAXSIZE;
        }
    }
}

PBTNode linkbintree_insertright(PBTNode r, BTDataType x)
{
    PBTNode p;
    if(!r)
    {
        return NULL;
    }
    p = (PBTNode)malloc(sizeof(BTNode));
    if(!p)
    {
        printf("creat btnote error, insert failed.\r\n");
        return;
    }
    p->data = x;
    p->left = NULL;
    p->right = r->right;
    r->right = p;
    return p;
}

void linkbintree_releasetree(PBTNode *r)
{
    if(*r)
    {
        linkbintree_releasetree(&(*r)->left);
        linkbintree_releasetree(&(*r)->right);
        free(*r);
    }
}

void linkbintree_deleteright(PBTNode r)
{
    if(!r)
    {
        return;
    }
    linkbintree_releasetree(&r->right);
    r->right = NULL;
}

void linkbintree_preorder(BiTreeLink r)
{
    if(r != NULL)
    {
        printf("%c\t", r->data);
        linkbintree_preorder(r->left);
        linkbintree_preorder(r->right);
    }
}

void linkbintree_nonpreorder(BiTreeLink r)
{
    PBTNode stack[MAXSIZE], p;
    int top = -1;
    p = r;
    while(p || top > -1)
    {
        if(p)
        {
            printf("%c \t", p->data);
            stack[++top] = p;
            p = p->left;
        }
        else
        {
            p = stack[top --];
            p = p->right;
        }
    }
}

void linkbintree_inorder(BiTreeLink r)
{
    if(r != NULL)
    {
        linkbintree_inorder(r->left);
        printf("%c\t", r->data);
        linkbintree_inorder(r->right);
    }
}

void linkbintree_noninorder(BiTreeLink r)
{
    PBTNode stack[MAXSIZE], p;
    int top = -1;
    p = r;
    while(p || top > -1)
    {
        if(!p)
        {
            p = stack[top --];
            printf("%c \t", p->data);
            p = p->right;
        }
        else
        {
            stack[++top] = p;
            p = p->left;
        }
    }
}

void linkbintree_postorder(BiTreeLink r)
{
    if(r != NULL)
    {
        linkbintree_postorder(r->left);
        linkbintree_postorder(r->right);
        printf("%c \t", r->data);
    }
}

void linkbintree_nonpostorder(BiTreeLink r)
{
    PBTNode stack[MAXSIZE], p;
    int flags[MAXSIZE];
    int top = -1, flag;
    p = r;

    do
    {
        if(p)
        {
            flag = 0;
            stack[++top] = p;
            flags[top] = flag;
            p = p->left;
        }
        else
        {
            flag = flags[top];
            p = stack[top --];
            if(flag == 0)
            {
                flag = 1;
                stack[++top] = p;
                flags[top] = flag;
                p = p->right;
            }
            else
            {
                printf("%c \t", p->data);
                p = NULL;
            }
        }
    }while(p || top > -1);
}

int linkbintree_count(BiTreeLink r)
{
    if(r == NULL)
    {
        return 0;
    }
    else
    {
        return linkbintree_count(r->left) + linkbintree_count(r->right) + 1;
    }
}

int linkbintree_depth(BiTreeLink r)
{
    int ld, rd;
    if(r == NULL)
    {
        return 0;
    }
    else
    {
        ld = linkbintree_depth(r->left);
        rd = linkbintree_depth(r->right);
        return ld > rd ? ld + 1 : rd + 1;
    }
}

PBTNode linkbintree_findnode(BiTreeLink r, BTDataType x)
{
    PBTNode p;
    if(r == NULL)
    {
        return NULL;
    }
    if(r->data == x)
    {
        return r;
    }
    p = linkbintree_findnode(r->left, x);
    if(p)
    {
        return p;
    }
    else
    {
        return linkbintree_findnode(r->right, x);
    }

}

int linkbintree_leafcount(BiTreeLink r)
{
    if(!r)
    {
        return 0;
    }
    else if(!r->left && !r->right)
    {
        return 1;
    }

    else
    {
        return linkbintree_leafcount(r->left) + linkbintree_leafcount(r->right);
    }
}

int linkbintree_test()
{
    PBTNode r;
    char nodes[] = "#RABC DE ";
    printf("*******************************\r\n");
    printf("Link binary tree\r\n");
    printf("*******************************\r\n");
    r = linkbintree_create(nodes, 1, 9);
    printf("leaf's count is %d \n", linkbintree_leafcount(r));

    linkbintree_display(r);
    printf("\n");
    linkbintree_preorder(r);
    printf("\n");
    linkbintree_inorder(r);
    printf("\n");
    linkbintree_postorder(r);
    printf("\n");
    return 0;
}








