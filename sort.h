#define MAXSIZE 100

typedef int KeyType; //key word type
typedef int DataType;

typedef struct{
    KeyType key;
    DataType data;
}SortItem, SqList[MAXSIZE];

void InsertSort(SqList L, int n);

void BiInsertSort(SqList L, int n);

void ShellSort(SqList L, int n);

void BubbleSort(SqList L, int n);

void QuickSort(SqList L, int low, int upper);

int Partition(SqList L, int i, int j);
