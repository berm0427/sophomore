package Shape_2; // 폴더 안에 들어있어서 추가함

public class Circle extends Shape
{
    @Override
    public void draw()
    {
        System.out.println("Circle");
    }

    public static void main(String[] args)
    {
        Shape b = new Circle();
        b.paint();
    }
}
