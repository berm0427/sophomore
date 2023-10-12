class Shape // Shape 클래스 선언
{
    public Shape next; // Shape 객체를 참조하는 next 선언
    public Shape() {next = null;} // next 참조 초기화

    public void draw() // draw 함수 선언
    {
        System.out.println("Shape");
    }
}

class Line extends Shape // Shape를 상속받는 Line 클래스 선언
{
    public void draw() // draw 함수 오버라이딩
    {
        System.out.println("Line");
    }
}

class Rect extends Shape // Shape를 상속받는 Rect 클래스 선언
{
    public void draw() // draw 함수 오버라이딩
    {
        System.out.println("Rect");
    }
}

class Circle extends Shape // Shape를 상속받는 Circle 클래스 선언
{
    public void draw() // draw 메서드 오버라이딩
    {
        System.out.println("Circle");
    }
}

public class MethodOverridingEx // 파일 이름과 같은 public class 선언
{
    static void paint(Shape p) // paint 메서드 선언
    {
        p.draw();
    }
    public static void main(String[] args) 
    {
        Line line = new Line(); // Line 객체 선언
        paint(line);
        paint(new Shape());// 객체 출력
        paint(new Line());// 객체 출력
        paint(new Rect());// 객체 출력
        paint(new Circle());// 객체 출력
    }
}