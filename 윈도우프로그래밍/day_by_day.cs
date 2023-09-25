namespace ConsoleApp1;

class Stdent
{
    public int year, month, day;
}
public class Program
{
    static void Main(string[] args)
    {
        Stdent SDay = new Stdent();
        SDay.year = 2035;
        SDay.month = 3;
        SDay.day = 2;

        Console.Write(" > 입학 일자 : ");
        Console.Write(SDay.year + "/" + SDay.month + "/");
        Console.WriteLine(SDay.day);
    } 
}