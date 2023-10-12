class Point
{
    private int x, y;
    public void set(int x, int y) // x,y를 받아 여기 클래스에 있는 x, y에 넣어주는 함수
    {
        this.x = x; this.y = y;
    }
    public void showPoint() // 현재 x, y 출력해주는 함수
    {
        System.out.println("("+ x + ","+y+")");
    }
}

class ColorPoint extends Point // ColorPoint를 상속받은 Point 클래스
{
    private String color;
    public void setColor(String color) // 컬러를 받아 여기 클래스에 있는 컬러에 넣어주는 함수
    { 
        this.color = color;
    }

    public void showColorPoint() // 현재 color 출력해주는 함수
    {
        System.out.print(color);
        showPoint();
    }
}

public class ColorPointEx // 파일이름과 public class 이름은 같아야 하므로, 파일 이름과 같은 public class 생성 (main func 선언 위함)
{   
    public static void main(String[] args) 
    {   
        Point p = new Point(); // Point 객체 생성
        p.set(1, 2);
        p.showPoint();

        ColorPoint cp = new ColorPoint(); // ColorPoint 객체 생성
        cp.set(3, 4);
        cp.setColor("red");
        cp.showColorPoint();
    }
}
