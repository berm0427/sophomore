#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 배열의 합을 계산하는 재귀 함수 정의
int recursive_sum(int arr[], int size)
{
    // 기본 사례: 배열이 비어 있으면 합이 0
    if (size == 0) 
    {
        return 0;
    }
    // 재귀함수: 합은 첫 번째 n-1 요소와 n번째 요소의 합
    else 
    {
        return arr[size - 1] + recursive_sum(arr, size - 1);
    }
}

int main()
{
    int size, i, sum;
    // 원하는 배열의 사이즈를 입력받는 구문
    printf("[>] 원하는 배열의 사이즈를 입력\n[<] ");
    scanf("%d", &size);
    
    // 크기에 맞게 메모리 할당하는 구문
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) 
    {
        printf("오류: 메모리 할당 실패! \n");
        return 1;
    }

    // 사용자 입력을 배열에 넣는 구문
    printf("[>] 정수 %d개 입력\n[<] ",size);
    for (i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // 재귀함수를 이용한 합계 계산
    sum = recursive_sum(arr, size);

    printf("[>] 배열의 합은 %d입니다.\n", sum);

    free(arr);

    return 0;
}
