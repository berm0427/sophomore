import java.util.Scanner; // 스캐너 사용을 위한 헤더 불러오기

public class ex_2_14
{
    public static void main(String[] args) 
    {
        char grade;
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("점수를 입력하세요(0~100): ");
        int score = scanner.nextInt(); // 정수 읽기
        switch (score/10)
        {
            case 10:// score = 100
            case 9: // score는 90 ~ 99
                grade = 'A';
                break;
            case 8: // score는 80 ~ 89
                grade = 'B';
                break;
            case 7: // score는 70 ~ 79
                grade = 'C';
                break;
            case 6: // score는 60 ~ 69
                grade = 'D';
                break;
            default: // score는 60 ~ 69
                grade = 'F';
        }
        
        System.out.println("학점은 " + grade + "입니다.");

        scanner.close();
    }
    

}
