class Person { } // Person 클래스 생성
class Student extends Person { } // Person을 상속 받은 Student 클래스 생성
class Researcher extends Person { } // Person을 상속 받은 Researcher 클래스 생성
class Professor extends Researcher { } // Researcher를 상속 받은 Student 클래스 생성

public class InstanceOfEx // 파일 이름과 같은 public class 생성
{
    static void print (Person p)
    {
        if (p instanceof Person) // Person의 인스턴스 이면
        {
            System.out.print("Person "); // Person 출력
        }

        if (p instanceof Student) /*  Student의 인스턴스이면 
                                    (else if를 사용하지 않는 이유는 모든 클래스는 Person을 상속받았기 때문에, 
                                    모두 Person에 해당된다 
                                    즉, else if를 여기서 부터 모두 적용할 경우 Person이라고만 출력되기때문에 사용하지 않는다.) */
        {
            System.out.print("Student "); // Student 출력
        }
        
        if (p instanceof Researcher) // Researcher의 인스턴스 이면
        {
            System.out.print("Researcher "); // Researcher 출력
        }

        if (p instanceof Professor) // Professor의 인스턴스 이면
        {
            System.out.print("Professor "); // Professor 출력
        }
        System.out.println(); // 아래줄로 내리기
    }

    public static void main(String[] args) 
    {
        System.out.print("new Student() -> \t"); print(new Student()); // 객체 출력
        System.out.print("new Researcher() -> \t"); print(new Researcher()); // 객체 출력
        System.out.print("new Professor() -> \t"); print(new Professor()); // 객체 출력
    }

        

}

