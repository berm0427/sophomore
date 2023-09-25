using System;
int[] a = { 10, 50 ,30 };
Array.Sort(a);
Console.WriteLine(" > 오름차순 정렬");

foreach (int cnt in a)
{
    Console.WriteLine(cnt + " ");
}
Console.WriteLine();
Array.Reverse(a);
Console.WriteLine(" > 내림차순 정렬");

foreach (int cnt in a)
{
    Console.WriteLine(cnt + " ");
}
Console.WriteLine();
for (int i = 0; i < a.Length; i++)
{
    Console.WriteLine(a[i] + " ");       
}

