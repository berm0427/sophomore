#include <stdio.h>

// 배열의 합을 계산하는 재귀 함수 정의
int sumArray(int arr[], int n) 
{
    // 기본 사례: 배열이 비어 있으면 합이 0
    if (n == 0) 
    {
        return 0;
    }
    // 재귀함수: 합은 첫 번째 n-1 요소와 n번째 요소의 합
    else 
    {
        return sumArray(arr, n-1) + arr[n-1];
    }
}

int main() 
{
    // 원하는 배열의 사이즈를 입력받는 구문
    int size;
    printf("[>] 원하는 배열의 사이즈를 입력\n[<] ");
    scanf("%d", &size);
    int arr[size];
    // 사용자 입력을 배열에 넣는 구문 
    printf("정수 %d개 입력: ", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    // 재귀함수를 이용한 합계 계산
    int total = sumArray(arr, size);
    // 결과 출력
    printf("배열의 합은 %d입니다.\n", total);
    return 0;
}
/*
이 프로그램에서, 우리는 배열과 정수 n을 인수로 취하는 sumArray라는 재귀 함수를 정의합니다.

n이 0이면 함수는 기본 대소문자인 0을 반환합니다. 

그렇지 않으면 함수는 n-1을 인수로 사용하여 자체 호출하고,

배열의 n번째 요소인 arr[n-1]의 값을 결과에 추가합니다. 

이것이 재귀함수의 기본입니다. 

n이 1인 함수를 호출하면 배열의 합인 arr[0]을 반환합니다.

메인함수에서는 먼저 사용자에게 입력을 요청하여 원하는 크기의 배열을 선언합니다. 
그런 다음 for 루프를 사용하여 배열을 사용자 입력으로 채웁니다. 

마지막으로 배열과 크기를 인수로 sumArray 함수를 호출하고 결과를 total 변수에 저장합니다. 

그런 다음 printf를 사용하여 결과를 인쇄합니다.
*/
