import java.io.*;

public class FileInputStreamEx {
	public static void main(String[] args) {
		byte b[] = new byte [6]; // 비어 있는 byte 배열
		String d = "C:\\Users\\user\\Desktop\\8장_강의자료\\8장_source\\8장\\chap08-ex05\\src\\test.out";
		try {
			// "c:\\Temp\\test.out" 파일을 읽어 배열 b에 저장
			FileInputStream fin = new FileInputStream(d);
			int n=0, c;
			while((c = fin.read())!= -1) { // -1은 파일 끝(EOF)
			//while((c = fin.read())!= null) {
				b[n] = (byte)c; // 읽은 바이트를 배열에 저장
				n++;
			}
			// 배열 b[]의 바이트 값을 모두 화면에 출력
			System.out.println(d + "에서 읽은 배열을 출력합니다.");
			for(int i=0; i<b.length; i++)
				System.out.print(b[i] + " ");
			System.out.println();
			
			fin.close();
		} catch(IOException e) {
			System.out.println(d + "에서 읽지 못했습니다. 경로명을 체크해보세요");
		}
	}
}