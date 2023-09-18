import java.util.Scanner;
public class Main 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int min = scanner.nextInt();
        int max = scanner.nextInt();
        int count = 0;
        for(int i = 1; i<=max; i++)
        {
            if(i*i <= max && i*i >= min)
            {
                count++;
            }
        }
        System.out.println(count);
        scanner.close();
    }   
}
