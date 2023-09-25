namespace ConsoleApp1
{
    class Dog
    {
        public int Age { get; set; }
        public string Color { get; set; }
        
        public Dog() { this.Age = 0; }

        public void Eat()
        {
            Console.WriteLine("냠냠 먹습니다");
        }

        public void Sleep()
        {
            Console.WriteLine("쿨쿨 잠을 잡니다");
        }

        public void Bark()
        {
            Console.WriteLine("왈왈 짖습니다");
        }
    }
    class Cat
    {
        public int Age { get; set; }
        public string Color { get; set; }
        
        public Cat() { this.Age = 0; }
        public void Eat()
        {
            Console.WriteLine("냠냠 먹습니다");
        }

        public void Sleep()
        {
            Console.WriteLine("쿨쿨 잠을 잡니다");
        }

        public void Meow()
        {
            Console.WriteLine("냥냥 웁니다");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Dog> Dogs = new List<Dog>() { new Dog(), new Dog(), new Dog() };
            List<Cat> Cats = new List<Cat>() { new Cat(), new Cat(), new Cat() };

            foreach (var item in Dogs)
            {
                item.Eat();
                item.Sleep();
                item.Bark();
            }
            
            foreach (var item in Cats)
            {
                item.Eat();
                item.Sleep();
                item.Meow();
            }
        }
    }
}

