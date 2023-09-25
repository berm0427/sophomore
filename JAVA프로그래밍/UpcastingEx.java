class Person
{
    String name;
    String id;

    public Person(String name)
    {
        this.name = name;
    }
}

class Student extends Person
{
    String grade;
    String department;

    public Student(String name)
    {
        super(name);
    }
}

public class UpcastingEx 
{
    public static void main(String[] args) 
    {
        Person p;
        Student s = new Student("이재문");
        p = s;
        
        System.out.println(p.name);

        ((Student)p).grade = "A";
        ((Student)p).department = "Com";

        System.out.println(((Student)p).grade);
        System.out.println(((Student)p).department);
    }
}
