public class test 
{
    public static void main(String[] args) 
    {
        int sum = 0;

        for(int i = 1; i<= 10; i++)
        { // 1 - 10 까지 반복
            sum += i; // 수를 누적하여 변수에 합하여 저장
            System.out.print(i); // 더하는 수 출력

            if(i <= 9) // 1 - 9 까지는 + 출력
            {
                System.out.print("+"); // println <-- 입력된 내용을 출력한후 개행, print < -- 입력한 내용만 출력하고 개행은 진행하지 않음
            }

            else // irk 10인경우
            {
                System.out.print('='); // '=' 출력하고
                System.out.println(sum);  // 덧셈 결과 출력
            }
        }    
    }

}
