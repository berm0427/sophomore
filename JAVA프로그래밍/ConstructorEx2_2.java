/*
 * ConstructorEx와 유사하기 때문에 중요한 부분만 각주를 달았습니다
 */


class A 
{
    public A(int x)
    {
        System.out.println("생성자A");
    }
}

class B extends A 
{
    public B() /*  인자가 void인 형식의 생성자가 A에 없음
                   Error! */
    {
        System.out.println("생성자B");
    }
}

public class ConstructorEx2_2
{
    public static void main(String[] args) 
    {
        B b = new B(); // 객체 생성
    }    
}