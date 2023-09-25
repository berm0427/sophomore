namespace ConsoleApp1
{
    class Animal
    {
        public int Age { get; set; }

        public Animal() { this.Age = 0; }

        public void Eat()
        {
            Console.WriteLine("냠냠 먹습니다");
        }

        public void Sleep()
        {
            Console.WriteLine("쿨쿨 잠을 잡니다");
        }
    }
    class Dog : Animal
    {
        public string Color { get; set; }
        public void Bark()
        {
            Console.WriteLine("왈왈 짓습니다");
        }

        public void Test()
        {
            Eat();
            Sleep();
        }
    }
    
    class Cat : Animal
    {
        public string Color { get; set; }
        
        public void Meow()
        {
            Console.WriteLine("냥냥 웁니다");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Animal> animals = new List<Animal>()
            {
                new Dog(), new Cat(), new Cat(), new Dog(),
                new Dog(), new Cat(), new Cat(), new Dog()
            };

            foreach (var item in animals)
            {
                item.Eat();
                item.Sleep();
            }
            
        }
    }
}

