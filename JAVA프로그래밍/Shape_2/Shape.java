package Shape_2; // 폴더 안에 들어있어서 추가함
// 폴더 두개 면-> package xxx.yyy
public class Shape 
{
    protected String name;
    public void paint()
    {
        draw();
    }

    public void draw()
    {
        System.out.println("Shape");
    }

    public static void main(String[] args)
    {
        Shape a = new Shape();
        a.paint();
    }
}
