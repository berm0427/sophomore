class Point // 클래스 Point 선언
{
    private int x,y; // 한점을 구성하는 x, y 좌표
    public Point() // x, y 초기화 함수
    {
        this.x = this.y = 0;
    }

    public Point(int x, int y) // 가져온 x, y를 넣어주는 함수
    {
        this.x = x; this.y = y;
    }

    public void showPoint() // x, y 출력해주는 함수
    {
        System.out.println("("+ x + ","+ y +")");
    }
}

class ColorPoint extends Point // Point를 상속받은 ColorPoint 클래스 생성
{
    private String color;
    public ColorPoint(int x, int y, String color) /*부모 클래스에 있는 매개변수가 x, y인 생성자를 호출하고
                                                    받은 컬러를 클래스내에 있는 컬러에 넣어주는 함수 */
    {
        super(x, y);
        this.color = color;
    }

    public void showColorPoint() // 컬러를 출력해주는 함수
    {
        System.out.println(color);
        showPoint();
    }
}

public class SuperEx // 파일이름과 같은 public class 생성
{
    public static void main(String[] args)
    {
        ColorPoint cp = new ColorPoint(5, 0, "blue"); // ColorPoint 객체 생성
        cp.showColorPoint();
    }    
}
