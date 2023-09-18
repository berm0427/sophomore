import java.util.Scanner;

public class Rectangle2
{
    int length_garo;
    int length_searo;
    int width;
    int height;

    public int getArea()
    {
        return width * height;
    }
    
    public int getwidth()
    {
        return length_garo * length_searo;
    }

    public static void main(String[] args) 
    {
        Rectangle2 rect = new Rectangle2();
        Scanner scanner = new Scanner(System.in);
        System.out.println("모드 선택 \n 1: 가로, 세로 길이로 계산 \n 2. 넓이와 높이로 계산");
        System.out.print(">> ");
        int num  = scanner.nextInt();
        if(num == 1)
        {
            System.out.println("가로, 세로 길이 및 높이를 입력");
            System.out.print(">> ");   
            rect.length_garo = scanner.nextInt();
            rect.length_searo = scanner.nextInt();
            rect.height = scanner.nextInt();
            int getArea = rect.getwidth() * rect.height;
            System.out.println("사각형의 면적은 " + getArea);
        }
        else if (num == 2)
        {
            System.out.println("넓이와 높이를 입력 입력");
            System.out.print(">> ");
            rect.width = scanner.nextInt();
            rect.height = scanner.nextInt();
            System.out.println("사각형의 면적은 " + rect.getArea());
        }
        
        scanner.close();
    }
}
