class Weapon // Weapon 클래스 선언
{
    protected int fire() // 함수 (메서드) 선언
    {
        return 1;
    }
}

class Cannon extends Weapon // Weapon을 상속받는 Cannon 선언
{
    @Override
    protected int fire() // 함수 오버라이딩
    {
        return 10;
    }
}


public class Overriding // 파일 이름과 같은 public class 선언
{
    public static void main(String[] args) 
    {
        Weapon weapon; // 객체 생성
        weapon = new Weapon(); // Weapon 객체로 생성
        System.out.println("기본 무기의 살상 능력은 " + weapon.fire()); // 출력

        weapon = new Cannon(); // Cannon 객체로 생성
        System.out.println("대포의 살상 능력은 " + weapon.fire()); // 츨력 
    }
}
