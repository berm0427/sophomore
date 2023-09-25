using System;

public class Print
{
    static public int calltimes;

    public Print()
    {
        Console.WriteLine("Hello World!");
        calltimes++;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Print print1 = new Print();
        Console.WriteLine(Print.calltimes);
        Print print2 = new Print();
        Console.WriteLine(Print.calltimes);
        Print print3 = new Print();
        Console.WriteLine(Print.calltimes);
    }
}

