#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 257097 // 배열의 최대 사이즈 (이 이상은 스택 오류가 발생함)
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
    printf("[>] 원하는 배열의 사이즈를 입력 (%d 까지)\n[<] ", MAX_SIZE);
    scanf("%d", &size);
    if (size > MAX_SIZE) 
    {
        printf("사이즈가 너무 커요!\n");
        return 1;
    }
    int arr[MAX_SIZE];
    // 사용자 입력을 배열에 넣는 구문 
    printf("[>] 정수 %d개 입력\n[<] ",size);
    for (i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    // 재귀함수를 이용한 합계 계산
    sum = recursive_sum(arr, size);
    printf("[>] 배열의 합은 %d입니다.\n", sum);
    return 0;
}
