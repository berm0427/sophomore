class Person
{
    private int weight;
    int age;
    protected int height;
    public String name;

    public void setWeight(int weight)
    {
        this.weight = weight;
    }

    public int getWeight()
    {
        return weight;
    }
}

class Student extends Person
{
    public void set()
    {
        age = 30;
        name = "홍길동";
        height = 175;
        weight = 99; // private이라 참조 X
        //setWeight(99);
    }
}

public class InheritanceEx_plus
{
    public static void main(String[] args) 
    {
        Student s = new Student();
        s.set();
        System.out.println(s.age + " " + s.name + " " + s.height + " " + s.weight);        
    }   
}
