/*
    MBCS1 실습
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h> // 교재에는 없지만 이게 있어애 실행 가능

int main(void)
{
    wchar_t str[] = L"ABC";
    int size = sizeof(str);
    int len = strlen(str);


    printf("배열의 크기 : %d \n", size);
    printf("문자열 길이 : %d \n", len);
}
