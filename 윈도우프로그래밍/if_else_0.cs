using System;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.Write("숫자 입력: ");
            int input = int.Parse(Console.ReadLine());

            if (input % 2 == 0)
            {
                Console.WriteLine("짝수입니다!");
            }

            else
            {
                Console.WriteLine("홀수입니다!");
            }
        }
    }
}

