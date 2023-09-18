import java.util.Scanner;
public class ex_3_1
{
    public static void main(String[] args)
    {
        int sum = 0;
        Scanner scanner = new Scanner(System.in);
        int EP = scanner.nextInt();
        for(int i = 1; i<=EP; i++)
        {
            sum +=i;
            System.out.print(i);
            if(i<=EP-1)
            {
                System.out.print("+");
            }
            else
            {
                System.out.print("=");
                System.out.print(sum);
            }   
            scanner.close();
        }   
    }
}
