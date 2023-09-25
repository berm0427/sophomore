using System;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.Write($"{DateTime.Now.Year} 년 ");
            Console.Write($"{DateTime.Now.Month} 월 ");
            Console.Write($"{DateTime.Now.Day} 일 ");
            Console.Write($"{DateTime.Now.Hour} 시 ");
            Console.Write($"{DateTime.Now.Minute} 분 ");
            Console.WriteLine($"{DateTime.Now.Second} 초 ");

            if (DateTime.Now.Hour < 12)
            {
                Console.WriteLine("오전입니다.");
            }

            else
            {
                Console.WriteLine("오후입니다.");
            }
        }
    }
}