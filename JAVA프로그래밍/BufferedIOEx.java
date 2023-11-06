import java.io.*;
import java.util.Scanner;

public class BufferedIOEx {
    public static void main(String[] args) {
        FileReader fin = null;
        int c;
        String d = "C:\\Users\\user\\Desktop\\8장_강의자료\\8장_source\\8장\\chap08-ex07\\src\\hangul2.txt";
        try {
            fin = new FileReader(d);
            BufferedOutputStream out = new BufferedOutputStream(System.out, 5);
            while ((c = fin.read()) != -1) { // 파일 데이터를 모두 스크린에 출력
                out.write(c);
            }
            // 파일 데이터가 모두 출력된 상태
            new Scanner(System.in).nextLine(); // <Enter> 키 입력, 키 입력 기다림 
            out.flush(); // 버퍼에 남아 있던 문자 모두 출력
            fin.close();
            out.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}