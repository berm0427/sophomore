class Person // 클래스 생성
{
    String name;
    String id;

    public Person(String name) // 생성자 생성
    {
        this.name = name; // 받은 name을 클래스 내의 name에 넣어줌
    }
}

class Student extends Person // Person을 상속받은 Student 클래스 생성
{
    String grade;
    String department;

    public Student(String name) // 생성자 생성
    {
        super(name); // 부모 생성자 호출
    }
}

public class UpcastingEx // 파일 이름과 유사한 public class 생성
{
    public static void main(String[] args) 
    {
        Person p; // 객체 생성
        Student s = new Student("이재문"); // 객체 생성
        p = s; // p에게 s가 참조한 것을 똑같이 참조하도록 함
        
        System.out.println(p.name);

        ((Student)p).grade = "A"; // 디폴트라 동일 패키지내에서 접근가능
        ((Student)p).department = "Com"; // 디폴트라 동일 패키지내에서 접근가능

        System.out.println(((Student)p).grade); // 출력
        System.out.println(((Student)p).department); // 출력
    }
}