using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] intArray;
            intArray = new int[] { 52, 273, 32, 65, 103 };

            intArray[0] = 0;

            Console.WriteLine(intArray[0]);
            Console.WriteLine(intArray[1]);
            Console.WriteLine(intArray[2]);
            Console.WriteLine(intArray[3]);

            string s = "Hello World!";
        
            Console.WriteLine(s[0]);
            Console.WriteLine(s[1]);
            Console.WriteLine(s[2]);
            Console.WriteLine(s[3]);
            Console.WriteLine(s[4]);
            Console.WriteLine(s[^1]);

            Console.WriteLine(s[1..4]);
            Console.WriteLine(s[^5..^2]);
            Console.WriteLine(s[..]);
            Console.WriteLine(s[..3]);
            Console.WriteLine(s[3..]);

            Range rng = 1..^0;
            Console.WriteLine(s[rng]);
        }
    }    
}
