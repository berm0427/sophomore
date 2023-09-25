using System;
// temp 변수를 사용하여 중간값을 저장
namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            int num1 = 0;
            int num2 = 0;
            int temp1 = 0;
            int temp2 = 0;
            for (int i = 0; i < num; i++)
            {
                if (i == 0 || i == 1)
                {
                    num1 = num2;
                    num2 = 1;
                }
                else
                {
                    temp1 = num1;
                    temp2 = num2;
                    num1 = temp2;
                    num2 = temp1 + temp2;
                }
            }

            Console.WriteLine(num2);
        }
        

    }
}