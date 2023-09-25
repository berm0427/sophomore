using System;

namespace ConSoleApp1
{
    public class Program
    {
        public static void Main(string[] args)
        {
            string firstName;
            string lastName;
            
            Console.WriteLine("Hey You!");
            Console.Write("Enter your first name: ");
            firstName = Console.ReadLine();
            Console.Write("Enter your last name: ");
            lastName = Console.ReadLine();

            Console.WriteLine("your full name is {1} {0}.", firstName, lastName);
            Console.WriteLine($"Your full name is {firstName} {lastName}.");
        }
    }
}