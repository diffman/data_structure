#define LISTSIZE 100

typedef int DataType;

typedef struct {
	DataType item[LISTSIZE];
	int length;
}seqlist;

//init sequence list
int list_init(seqlist *L);

int list_get_length(seqlist L);

int list_is_empty(seqlist L);

int list_insert(seqlist *L, int pos, DataType item);

int list_delete(seqlist *L, int pos, DataType *item);

int list_find(seqlist L, DataType item);

int list_get_elem(seqlist L, int pos, DataType *item);

int list_traverse(seqlist L);

