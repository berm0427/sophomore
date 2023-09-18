using System;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("{0},{1}, {2}", "Hello", " World!", "C#");
            Console.WriteLine("{1},{0}, {2}", "Hello", " World!", "C#");
            Console.WriteLine("{0}{1}, {2}", "Hello", " World!", "C#");
            Console.WriteLine("{1}{1}, {2}", "Hello", " World!", "C#");
            Console.WriteLine("{1}{0}, {2}", "Hello", " World!", "C#");
            Console.WriteLine("{0}{0}, {2}", "Hello", " World!", "C#");
        }
    }
}
