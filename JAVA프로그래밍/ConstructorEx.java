class A // 클래스 생성
{
    public A() // 메소드 생성
    {
        System.out.println("생성자A");
    }
}

class B extends A // A 상속 받은 B생성
{
    public B() // 메소드 생성
    {
        System.out.println("생성자B");
    }
}

class C extends B // B 상속받은 C 생성
{
    public C() // 메소드 생성
    {
        System.out.println("생성자C");
    }
}

public class ConstructorEx // 파일이름과 유사한 public class 생성
{
    public static void main(String[] args) 
    {
        C c = new C(); // 객체 생성
    }    
}