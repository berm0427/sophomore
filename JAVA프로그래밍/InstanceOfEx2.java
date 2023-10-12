/*
InstanceOfEx와 내용은 같아 전체적인 설명은 넣지 않았습니다
전체적인 설명은 InstanceOfEx를 참조해주세요
 */

class Person { }
class Student extends Person { }
class Researcher extends Person { }
class Professor extends Researcher { }

public class InstanceOfEx2
{
    static void print (Person p)
    {
        if (p instanceof Person)
        {
            System.out.print("Person ");
        }

        else if (p instanceof Student) /* 만일 else if로 실행하면 -> else if가 위에 내용이 아니면 출력한다는 이야기 이므로 
                                                                    위에있는 Person만 출력*/
        {
            System.out.print("Student ");
        }
        
        else if (p instanceof Researcher)
        {
            System.out.print("Researcher ");
        }

        else if (p instanceof Professor)
        {
            System.out.print("Professor ");
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {
        System.out.print("new Student() -> \t"); print(new Student());
        System.out.print("new Researcher() -> \t"); print(new Researcher());
        System.out.print("new Professor() -> \t"); print(new Professor());
    }

        

}

