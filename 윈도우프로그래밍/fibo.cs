using System;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());

            Console.WriteLine(fibo(num));
        }
        
        static int fibo(int num)
        {
            if (num <= 1)
            {
                return 1;
            }
            else if (num == 1 || num == 2)
            {
                return 1;
            }
            else
            {
                return fibo(num - 1) + fibo(num - 2);
            }
        }
    }
}