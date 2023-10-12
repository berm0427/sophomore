/*
 * 업캐스팅: 자식 클래스의 객체가 부모 클래스 타입으로 형변횐 되는 것
 * 다운캐스팅: 부모 클래스의 객체가 자식 클래스 타입으로 형변횐 되는 것
 */

class Person // 클래스 선언
{
    String name;
    String id;
    public Person (String name) // 생성자 선언
    {
        this.name = name;
    }
}

class Student extends Person // Person을 상속받는 Student 클래스 생성
{
    String grade;
    String department;
    public Student(String name) // 생성자 생성
    {
        super(name); // 부모 클래스 생성자 호출
    }
}

public class DowncastingEx // 파일의 이름과 유사한 public class 생성
{
    public static void main(String[] args) 
    {
        Person p = new Student("이재문"); // 업캐스팅
        Student s;

        s = (Student)p; // 다운캐스팅

        System.out.println(s.name); // 오류 없음
        s.grade = "A"; // 오류 없음

    }
}
