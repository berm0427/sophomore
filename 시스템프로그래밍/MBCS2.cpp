/*
    MBCS1 실습
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h> //

int main(void)
{
    wchar_t str[] = L"ABC";
    int size = sizeof(str);
    int len = wcslen(str); //이걸 변경함


    printf("배열의 크기 : %d \n", size);
    printf("문자열 길이 : %d \n", len);
}
