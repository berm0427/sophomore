/*
 * 추상 클래스는 클래스 내 '추상 메소드'가 하나 이상 포함되거나 abstract로 정의된 경우를 말합니다. 
 * 반면 인터페이스는 모든 메소드가 추상 메소드인 경우를 말합니다.
 * 인터페이스(Interface)는 Java에서 추상 메서드만을 선언할 수 있는 것이 일반적인 규칙이지만, 
 * Java 8부터부터는 인터페이스에 default 메서드와 static 메서드도 선언할 수 있게 되었습니다. 
 * 그리고 Java 9부터는 private 메서드도 인터페이스에 추가할 수 있게 되었습니다./ +
 * //
 */


interface PhoneInterface // 인터페이스 선언 (추상 메서드와 비슷하나 다중 상속이 가능하다)
{
    final int TIMEOUT = 10000; // 상수 선언
    void sendCall(); // 추상 메소드
    void receiveCall(); // 추상 메소드
    default void printLogo() // printlogo 메소드 선언
    {
        System.out.println("** Phone **");
    }
}

class SamsungPhone implements PhoneInterface
{
    @Override
    public void sendCall() // 추상 메소드 오버라이딩
    {
        System.out.println("띠리리리링");
    }
    @Override
    public void receiveCall() // 추상 메소드 오버라이딩
    {
        System.out.println("전화가 왔습니다.");
    }

    public void flash() // 메소드 추가
    {
        System.out.println("전화기에 불이 켜졌습니다.");
    }
}

public class InterfaceEx // 파일 이름과 같은 public class 생성
{
    public static void main(String[] args)
    {
        SamsungPhone phone = new SamsungPhone(); // 객체 생성
        phone.printLogo();
        phone.sendCall();
        phone.receiveCall();
        phone.flash();    
    }
}