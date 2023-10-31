using System;

namespace exam

{

    public class calc

    {

        public static int sum (int n, int m)

        {

            int sum_r = 0;

            for(int i = n; i <= m; i++)

            {

                sum_r += i;

            }
            return sum_r;

        }

        public static void Main(string[] args)

        { 

            Console.Write("> 시작 :  ");

            int n = int.Parse(Console.ReadLine());

            Console.Write("> 종료 :  ");

            int m = int.Parse(Console.ReadLine());
        

            Console.WriteLine("> {0}부터 {1}까지 누적합계 :  {2}", n, m, sum(n,m) );

        }
    }
}
