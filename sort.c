#include "sort.h"
#include <stdio.h>

//直接插入排序
void InsertSort(SqList L, int n)
{
    int i, j;
    SortItem p;

    for(i = 1; i < n; i ++)
    {
        p = L[i];
        for(j = i -1; j >= 0 && p.key < L[j].key; j --) //find insert position.
        {
            L[j + 1] = L[j];
        }

        L[j + 1] = p;//insert.
    }

}

//折半插入排序
void BiInsertSort(SqList L, int n)
{
    int i, j, low, upper, mid;
    SortItem p;

    for(i = 1; i < n; i ++)
    {
        p = L[i];
        low = 0;
        upper = i - 1;
        while(low <= upper)
        {
            mid = (low + upper) / 2;
            if(p.key < L[mid].key)
            {
                upper = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }

        for(j = i -1; j >= low; j --)
        {
            L[j + 1] = L[j];
        }
        L[low] = p;
    }
}

//Shell排序
void ShellSort(SqList L, int n)
{
    int i, j, d;
    SortItem p;

    for(d = n / 2; d >= 1; d /= 2)
    {
        for(i = d; i < n; i ++)
        {
            p = L[i];
            for(j = i - d; j >= 0 && p.key < L[j].key; j -= d)
            {
                L[j + d] = L[j];
            }

            L[j + d] = p;
        }

        for(i = 0; i < n; i ++)
        {
            printf("%d \t", L[i].key);
        }
        printf("\n\n");
    }
}

//冒泡排序
void BubbleSort(SqList L, int n)
{
    int i, j, over;
    SortItem p;

    for(i = 0; i < n -1; i ++)
    {
        over = 1;
        for(j = n - 1; j > i; j --)
        {
            if(L[j].key < L[j - 1].key)
            {
                p = L[j];
                L[j] = L[j - 1];
                L[j - 1] = p;
                over = 0;
            }
        }
        for (j = 0; j < n; j ++)
        {
            printf("%d \t", L[j].key);
        }
        printf("\n\n");
        if(over)
        {
            break;
        }

    }
}

//快速排序
void QuickSort(SqList L, int low, int upper)
{
    int pivot;
    if(low < upper)
    {

        pivot = Partition(L, low, upper);
        QuickSort(L, low, pivot);
        QuickSort(L, pivot + 1, upper);
    }
}

int Partition(SqList L, int i, int j)
{
    SortItem pivot;
    //int k, n = j;

    pivot = L[i];
    while(i < j)
    {
        while(i < j && pivot.key <= L[j].key)
        {
            j --;
        }
        if(i < j)
        {
            L[i] = L[j];
            i ++;
        }

        while(i < j && pivot.key > L[i].key)
        {
            i ++;
        }
        if(i < j)
        {
            L[j] = L[i];
            j --;
        }
    }

    L[i] = pivot;
   // for (k = 0; k < n; k ++)
    //{
   //     printf("%d \t", L[k].key);
   // }
   // printf("\n\n");
    return i;
}


int main(int argc, char * argv[])
{
    SqList L;
    KeyType item[] = {25, 22, 8, 33, 11,44,  67, 45, 3};
    int i, n = 9;

    for(i = 0; i < n; i ++)
    {
        L[i].key = item[i];
    }
    //InsertSort(L, n);
    //BiInsertSort(L, n);
    //ShellSort(L, n);
    //BubbleSort(L, n );

    QuickSort(L, 0, 8);
    for (i = 0; i < n; i++)
    {
        printf("%d \t", L[i].key);
    }

    printf("\n");
    return 0;
}






