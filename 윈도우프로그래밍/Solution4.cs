class Solution
{
    static void Main(string[] args)
    {
        List<int> list = new List<int>();
        list.Add(123);
        list.Add(35);
        list.Add(78);
        list.Add(98);

        Console.WriteLine(" > 리스트 요소 제거 전 ");
        foreach (var item in list)
        {
            Console.WriteLine(" 요소 : {0, 3}", item);
        }

        Console.WriteLine(" > 리스트 요소 개수 : {0}", list.Count);
        Console.WriteLine();

        list.Remove(35);
        Console.WriteLine(" > 리스트 요소 제거 후 ");
        foreach (var item in list)
        {
            Console.WriteLine(" 요소 : {0, 3}", item);
        }

        Console.WriteLine(" > 리스트 요소 개수 : {0}", list.Count);
    }
}