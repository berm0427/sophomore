/*
    WBCS 실습 2
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h> // 교재에는 없지만 이게 있어야 실행 가능 (visual studio(윈도우 기반 C)에서는 자동으로 가지고 와서 필요가 없는데 다른데에서는 여기에 넣어주어야..)
#include <locale.h>

int main(int argc/* 배열 번지(카운팅,몇 개를 입력했느냐?)*/, char* argc[]/* 뒤에 문자를 받아서 프로그램에 쓸때 사용*/)
{
    _wsetlocale(LC_ALL,L"korean");
    wchar_t str[] = L"ABC한글";
    int size = sizeof(str);
    int len = wcslen(str); //이걸 변경함


    wprintf(L"Array size : %d \n", size);
    wprintf(L"string Length : %d \n", len);
    wprintf(L"%s\n", str);
    
    return 0;
}
