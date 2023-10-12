abstract class Calculator // 추상 클래스 선언 (자식 클래스에서 반드시 오버라이딩 필요)
{
    public abstract int add(int a, int b);
    public abstract int subtract(int a, int b);
    public abstract double average(int[] a);
}

public class GoodCalc extends Calculator // 자식 클래스인 Calculator 선언
{
    @Override
    public int add(int a, int b) // add 오버라이딩
    {
        return a + b;
    }
    @Override
    public int subtract (int a, int b) // sub 오버라이딩
    {
        return a- b;
    }
    @Override
    public double average(int[] a) // aver 오버라이딩
    {
        double sum = 0;
        for(int i = 0; i < a.length; i++)
        {
            sum +=a[i];
        }
        return sum / a.length;
    }

    public static void main(String[] args) // 사실 public class가 없어도 메인은 선언할 수 있다  
    {
        GoodCalc c = new GoodCalc(); // 객체 생성
        System.out.println(c.add(2, 3)); // add 출력
        System.out.println(c.subtract(2, 3)); // sub 출력
        System.out.println(c.average(new int[] {2,3,4})); // aver 출력
    }

}