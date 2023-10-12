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

        else if (p instanceof Student)
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

