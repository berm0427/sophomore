using System;
// temp 변수를 사용하여 중간값을 저장
namespace ConsoleApp1
{
    public class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            Console.WriteLine(int.Parse(s[0]) * int.Parse(s[1]));
            // 한 줄로 입력받아 계산하는 것
        }
        

    }
}