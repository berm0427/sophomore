using System;
int[] Array1 = { -1, 0, 1, 2, 3 };
int[] Array2 = new int[] { 1, 2, 3, 4, 5, 6, 7 };

foreach (int cnt in Array1)
{
    Console.Write(cnt + " ");
}
Console.WriteLine();

foreach(int cnt in Array2)
{
    Console.Write(cnt + " ");
}
Console.WriteLine("\n");

int[,] number2D = new int[3,2] {{1, 3}, {5, 7}, {6, 8}};
Console.WriteLine();
foreach (int cnt in number2D)
{
    Console.WriteLine(cnt + " ");
}
Console.WriteLine("\n");
int[] Array_Rank1 = { 10, 50, 30 };
int[,] Array_Rank2 = { {1, 2, 3}, {4, 5, 6} };

int d1 = Array_Rank1.Rank;
int d2 = Array_Rank2.Rank;

Console.WriteLine(" > 차원 수 : " + d1);
Console.WriteLine(" > 차원 수 : " + d2);
