class Person // Person class 생성
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

class Student extends Person // Person을 상속받은 Student class 생성
{
    public void set()
    {
        age = 30;
        name = "홍길동";
        height = 175;
        // weight = 99;
        setWeight(99);
    }
}

public class InheritanceEx // 파일이름과 같은 public class 생성
{
    public static void main(String[] args) 
    {
        Student s = new Student(); // student 객체 생성
        s.set();
        System.out.println(s.age + " " + s.name + " " + s.height + " " + s.getWeight()); // 출력    
    }   
}