/*
 * ConstructorEx와 유사하기 때문에 중요한 부분만 각주를 달았습니다
 */


class A 
{
    public A() 
    {
        System.out.println("생성자A");
    }

    public A (int x) // 정수를 인자로 받는 생성자 생성
    {
       
    }
}

class B extends A 
{
    public B() 
    {
        System.out.println("생성자B");
    }
}

public class ConstructorEx2
{
    public static void main(String[] args) 
    {
        B b = new B(); // 객체 생성
    }    
}