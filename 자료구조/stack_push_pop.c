#include <stdio.h>
#include <stdlib.h>

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* A)
{
	A->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* A)
{
	return (A->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* A)
{
	return (A->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* A, element item)
{
	if (is_full(A)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else A->data[++(A->top)] = item;
}
// 삭제함수
element pop(StackType* A)
{
	if (is_empty(A)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return A->data[(A->top)--];
}
// 피크함수
element peek(StackType* A)
{
	if (is_empty(A)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return A->data[A->top];
}
// ===== 스택 코드의 끝 ===== 


int main(void)
{
	StackType* A;


	A = (StackType*)malloc(sizeof(StackType));
	init_stack(A);
	push(A, 1);
	push(A, 2);
	push(A, 3);
	pop(A);
	push(A, 4);
	push(A, 5);
	
	printf("[>]스택의 내용: ");
	for (int i = 0; i <= A->top; i++) 
	{
		printf("%d ", A->data[i]);
	}
	printf("\n");
	printf("[>]스택의 끝이 가리키는 내용: %d\n", peek(A));
	free(A);
}
