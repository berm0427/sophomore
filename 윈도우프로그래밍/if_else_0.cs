using System;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.Write("���� �Է�: ");
            int input = int.Parse(Console.ReadLine());

            if (input % 2 == 0)
            {
                Console.WriteLine("¦���Դϴ�!");
            }

            else
            {
                Console.WriteLine("Ȧ���Դϴ�!");
            }
        }
    }
}

