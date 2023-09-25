using System;

class Solution2
{
    static void Main(string[] args)
    {
        Output(15);
        Output(12.35);
        Output("파이 값 = ", 3.141592);
    }

    private static void Output(double a)
    {
        Console.Write(" > 실수값 출력 : ");
        Console.WriteLine(a);
    }
    private static void Output(string s, double a)
    {
        Console.Write(" > 문자열 + 실수값 출력 : ");
        Console.WriteLine(s+a);
    }
    private static void Output(int a)
    {
        Console.Write(" > 정수값 출력 : ");
        Console.WriteLine(a);
    }
}