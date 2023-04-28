#define MAX_LIST_SIZE 100 // 리스트의 최대크기
#include <stdio.h>
typedef int element; //항목 정의

typedef struct
{
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; //현재 리스트에 저장된 항목들의 개수
}ArrayListType;

//오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(ArrayListType* L)
{
	L->size = 0;
}
//리스트가 비어있으면 1을 반환
//그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
//리스트가 가득차있으면 1을 반환
//그렇지 않으면 0을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
	{
		error("위치오류");
		return L->array[pos];
	}
}
//리스트 출력
void print_list(ArrayListType* L)
{
	for (int i = 0; i < L->size; i++)
	{
		fprintf(stdout, "%d->", L->array);
	}
	fprintf(stdout, "\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE)
	{
		error("리스트 오버플로우");
	}
	L->array[L->size] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for(int i = (L->))
	}
}
int main()
{

}
