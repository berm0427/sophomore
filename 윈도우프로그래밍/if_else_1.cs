using System;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.Write($"{DateTime.Now.Year} �� ");
            Console.Write($"{DateTime.Now.Month} �� ");
            Console.Write($"{DateTime.Now.Day} �� ");
            Console.Write($"{DateTime.Now.Hour} �� ");
            Console.Write($"{DateTime.Now.Minute} �� ");
            Console.WriteLine($"{DateTime.Now.Second} �� ");

            if (DateTime.Now.Hour < 12)
            {
                Console.WriteLine("�����Դϴ�.");
            }

            else
            {
                Console.WriteLine("�����Դϴ�.");
            }
        }
    }
}