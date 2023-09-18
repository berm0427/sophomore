public class Circle
{
    int radius;
    String name;

    public Circle()
    {
    }
    public double getArea()
    {
        return 3.141592 * radius * radius;
    }
    public static void main(String[] args) 
    {   
        Circle pizza;
        pizza = new Circle();
        pizza.radius = 10;
        pizza.name = "자바 피자";
        double area = pizza.getArea();
        System.out.println(pizza.name + "의 면적은 " + area);

        Circle donut = new Circle();
        donut.radius = 2;
        donut.name = "자바도넛";
        area = donut.getArea();
        System.out.println(donut.name + "의 면적은 "+area);
    }
}