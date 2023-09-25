namespace ConsoleApp1
{
    class BaseClass
    {
        public int a, b;
        public BaseClass()
        {
            a = 1;
            b = 1;
        }

        public BaseClass(int a, int b)
        {
            this.a = a;
            this.b = b;
        }
    }

    class DerivedClass : BaseClass
    {
        public int c;
        public DerivedClass()
        {
            c = 1;
        }

        public DerivedClass(int a, int b, int c) : base(a, b)
        {
            this.c = c;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            DerivedClass obj1 = new DerivedClass();
            DerivedClass obj2 = new DerivedClass(1,2,3);
            Console.WriteLine("a = {0}, b = {1}, c = {2}", obj1.a, obj1.b, obj1.c);
            Console.WriteLine("a = {0}, b = {1}, c = {2}", obj2.a, obj2.b, obj2.c);
        }
    }
}