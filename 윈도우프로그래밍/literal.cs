using System;

namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("리티럴을 double 형식으로 " + 1.618033988749895);
            Console.WriteLine("리티럴을 decimal 형식으로 " + 1.618033988749895);
            Console.WriteLine(9_814_072_256);
            Console.WriteLine(6.023E23F);
            Console.WriteLine(0x002A);
            Console.WriteLine($"0x{42:X}");

            const double number = 1.618033988749895;
            double result;
            string text;
            string option = "/help";

            text = $"{number}";
            result = double.Parse(text);
            Console.WriteLine($"{result == number}: {result} == {number}");
        }
    }
}