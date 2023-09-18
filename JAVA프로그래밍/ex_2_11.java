import java.util.Scanner; // 스캐너 사용을 위한 헤더 불러오기

public class ex_2_11 
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in); // 스캐너 선언

        System.out.print("수를 입력하시오: ");
        int number = scanner.nextInt(); // 정수 입력
        if(number % 3 == 0) // 3으로 나눈 나머지가 0인지 검사
        {
            System.out.println("3의 배수입니다");
        }
        else
        {
            System.out.println("3의 배수가 아닙니다");
        }

        scanner.close();
    }
}
