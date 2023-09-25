using System;

public class EnumTest
{
    enum Days { SaturDay, SunDay, MonDay, Tuesday, WednesDay, ThurrsDay, Friday}

    enum Season
    {
        Spring,
        Summer,
        Autumn,
        Winter
    }

    static void Main(string[] args)
    {
        Type Weekdays = typeof(Days);
        Console.WriteLine("The days of the week, and their corresponding values in the Days Enum are: ");
        foreach (string s in Enum.GetNames(Weekdays))
        {
            Console.WriteLine(s);
        }
        Console.WriteLine();
        foreach (var item in Enum.GetValues(typeof(Season)))
        {
            Console.WriteLine(item);
        }
    }
}