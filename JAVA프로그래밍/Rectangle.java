import java.util.Scanner;

public class Rectangle
{
    int width;
    int height;

    public int getArea()
    {
        return width * height;
    }

    public static void main(String[] args) 
    {
        Rectangle2 rect = new Rectangle2();
        Scanner scanner = new Scanner(System.in);
        System.out.println("구하려는 사각형의 넓이와 높이를 입력하세요");
        System.out.print(">> ");
        
        rect.width = scanner.nextInt();
        rect.height = scanner.nextInt();

        System.out.println("사각형의 면적은 " + rect.getArea());

        scanner.close();
    }
}

