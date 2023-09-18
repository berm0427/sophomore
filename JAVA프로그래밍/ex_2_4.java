import java.util.Scanner; // 스캐너 사용을 위한 헤더 불러오기

public class ex_2_4 
{
    public static void main(String[] args)
    {
        System.out.println("이름, 도시, 나이, 키(신장), 체중, 독신 여부를 빈칸으로 분리하여 입력하세요");
        Scanner scanner = new Scanner(System.in); // 스캐너 선언

        String name = scanner.next(); // 문자열 읽기
        System.out.print("이름은 " + name + ", ");

        String city = scanner.next(); // 문자열 읽기
        System.out.print("도시는 " + city + ", ");

        int age = scanner.nextInt(); // 정수 읽기
        System.out.print("나이는 " + age + "살, ");

        double height = scanner.nextDouble(); // 실수 읽기
        System.out.print("신장은 " + height + ", ");

        double weight = scanner.nextDouble(); // 실수 읽기
        System.out.print("체중은 " + weight + ", ");

        boolean isSingle = scanner.nextBoolean(); // 논리값 읽기
        System.out.println("독신 여부는 " + isSingle + "입니다");
        scanner.close();
    }
}
