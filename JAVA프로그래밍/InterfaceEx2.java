/*
 * InterfaceEx와 유사하기 때문에 중요한 부분만 각주를 넣겠습니다 
 */

interface PhoneInterface // 인터페이스 선언
{
    final int TIMEOUT = 10000; 
    void sendCall(); 
    void receiveCall();
    default void printLogo()
    {
        System.out.println("** Phone **");
    }
}

interface MobliePhoneInterface extends PhoneInterface // PhoneInterface를 상속받는 인터페이스인 MobliePhoneInterface 선언
{
    void sendSMS();
    void receiveSMS();
}

interface MP3Interface  // MP3Interface 인터페이스 선언
{
    public void play();
    public void stop();
}

class PDA // 계산 기능을 넣은 PDA 클래스 선언
{
    public int Calculate(int x, int y)
    {
        return x + y;
    }
}


class SmartPhone extends PDA implements MobliePhoneInterface, MP3Interface /*  PDA class와 
                                                                               MobliePhoneInterface, MP3Interface 인터페이스를 상속받는 SmartPhone클래스 선언 */
{
    @Override
    public void sendCall() // 추상메소드 오버라이딩
    {
        System.out.println("따르릉따르릉~~");
    }

    @Override
    public void receiveCall() // 추상메소드 오버라이딩
    {
        System.out.println("전화가 왔어요.");
    }

    @Override
    public void sendSMS() // 추상메소드 오버라이딩
    {
        System.out.println("문자갑니다.");
    }

    @Override
    public void receiveSMS() // 추상메소드 오버라이딩
    {
        System.out.println("문자왔어요.");
    }

    @Override
    public void play() // 추상메소드 오버라이딩
    {
        System.out.println("음악 연주합니다.");
    }

    @Override
    public void stop() // 추상메소드 오버라이딩
    {

        System.out.println("음악 중단합니다.");
    }

    public void schedule() // 추상메소드 오버라이딩
    {
        System.out.println("일정 관리합니다.");
    }
}

public class InterfaceEx2 // 파일 이름과 같은 public class 선언
{
    public static void main(String[] args)
    {
        SmartPhone phone = new SmartPhone(); // 객체 생성
        phone.printLogo();
        phone.sendCall();
        phone.play();
        phone.sendSMS();
        System.out.println("3과 5를 더하면 "+ phone.Calculate(3, 5));
        phone.schedule();
    }
}
