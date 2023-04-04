#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5
typedef int element;
element A[MAX_STACK_SIZE];
int top = -1;

int empty()
{
    return(top == -1);
}

int full()
{
    return(top == (MAX_STACK_SIZE-1));
}

void push(element * Stack, element item)
{
    if(full())
    {
        fprintf(stderr, "스택 포화");
        return;
    }
    else Stack[++top] = item;
}

void pop()
{
    if(empty())
    {
        fprintf(stderr, "스택 공백");
        exit(1);
    }
    else A[top--] = 0;
}

int main()
{
    push(A, 1);
    push(A, 2);
    push(A, 3);
    pop();
    push(A, 4);
    push(A, 5);

    printf("[>]스택의 내용: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("[>]스택의 끝이 가리키는 내용: %d\n", A[top]);

    return 0;
}
