using ConsoleApp1.A;
using ConsoleApp1.C;

namespace ConsoleApp1
{
    namespace A
    {
        class Parent
        {
            public Parent()
            {
                Console.WriteLine("부모 생성자");
            }
        }

        class Child : Parent
        {
            public Child()
            {
                Console.WriteLine("자식 생성자");
            }
        }
    }

    namespace B
    {
        class Parent
        {
            public Parent()
            {
                Console.WriteLine("부모 생성자");
            }
            
        }

        class Child : Parent
            {
                public Child() : base()
                {
                    Console.WriteLine("자식 생성자");
                }
            }
        
    }

    namespace C
    {
        class Parent
        {
            public Parent()
            {
                Console.WriteLine("Parent()");
            }

            public Parent(int param)
            {
                Console.WriteLine("Parent(int param)");
            }

            public Parent(String param)
            {
                Console.WriteLine("Parent(String param)");
            }
        }

        class Child : Parent
        {
            public Child()
            {
                Console.WriteLine("Child() : base(10)");
            }

            public Child(String input) : base(input)
            {
                Console.WriteLine("Child(string input) : base(input)");
            }
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            A.Child childA = new A.Child();
            Console.WriteLine();

            B.Child childB = new B.Child();
            Console.WriteLine();

            C.Child childC = new C.Child();
            C.Child childD = new C.Child("String");
        }
    }
}



