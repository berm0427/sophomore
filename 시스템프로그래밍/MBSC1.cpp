/*
    MBCS 실습 1
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h> // 교재에는 없지만 이게 있어야 실행 가능 (visual studio(윈도우 기반 C)에서는 자동으로 가지고 와서 필요가 없는데 다른데에서는 여기에 넣어주어야..)

int main(void)
{
    wchar_t str[] = L"ABC"; //여기서 문제가 발생한다고 한다
    int size = sizeof(str);
    int len = strlen(str); // WBCS 기반의 문자열 함수로 변경을 해주어야 한다


    printf("배열의 크기 : %d \n", size);
    printf("문자열 길이 : %d \n", len);
    
    return 0;
}
