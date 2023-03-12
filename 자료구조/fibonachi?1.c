#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    printf("[>] 원하는 사이즈 입력:\n[<] ");
    scanf("%d", &size);

    int* arr = malloc(sizeof(int) * size); // 원하는 사이즈로 할당해준다 (int 4byte * 원하는 크기로 해야 정상작동)
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        sum = sum+arr[i];
    }

    printf("[>] 피보나치 계산 결과는 %d", sum);
    free(arr);
}
