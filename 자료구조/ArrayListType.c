#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L) {
	L->size = 0;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치오류");
	return L->array[pos];
}

void print_list(ArrayListType* L) {
	for (int i = 0; i < L->size; i++)
		printf("%d -> ", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE)
		error("리스트 오버플로우");
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = L->size; i > pos; i--)
			L->array[i] = L->array[i - 1];
		L->array[pos] = item;
		L->size++;
	}
	else error("포지션이 유효하지 않습니다.");
}

int main() {
	ArrayListType list;
	
	init(&list);
	insert(&list, 0, 10);
	insert(&list, 0, 20);
	insert_last(&list, 30);
	insert_last(&list, 40);
	print_list(&list);
	
	return 0;
}
