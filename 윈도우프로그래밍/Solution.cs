using System;

class Solution
{
    static void Main(string[] args)
    {
        Console.WriteLine(" > 5개로 구성된 피라미드 ");
        DrawPyramid(5);
        
        Console.WriteLine(" > 8개로 구성된 피라미드 ");
        DrawPyramid(8);
    }

    static void DrawPyramid(int n)
    {
        for (int count = 1; count <= n; count++)
        {
            // 별 찍기 전 공백 추가
            for (int s = 1; s <= n - count; s++)
            {
                Console.Write(" ");
            }

            // 별 인쇄
            for (int star = 1; star <= 2 * count - 1; star++)
            {
                Console.Write("*");
            }

            // 다음줄로 넘기기
            Console.WriteLine();
        }
        Console.WriteLine();
    }
}
/* 오류난 코드
    static void DrawPyramid(int n)
    {
        for (int count = 1; count <= n; count++)
        {
            for (int s = 1; s <= n - count; s++)
            {
                Console.Write(" ");
                for (int star = 1; star <= 2 * count - 1; star++) <-- 뭐허니?
                {
                    Console.Write("*");
                }

                Console.WriteLine();
            }
        }
        Console.WriteLine();
    }
*/