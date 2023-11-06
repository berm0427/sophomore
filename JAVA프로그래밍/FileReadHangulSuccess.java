import java.io.*;

public class FileReadHangulSuccess {
	public static void main(String[] args) {
		InputStreamReader in = null;
		FileInputStream fin = null;
		try {
			//fin = new FileInputStream("/Users/soma/doc_native/programing/JAVA/예제 및 그림 소스/8장/chap08-ex02/src/hangul.txt");
			//in = new InputStreamReader(fin, "UTF-8"); // 맥의 경우 올바른 문자 집합 지정
			//in = new InputStreamReader(fin, "MS949"); //윈도우의 경우 올바른 문자 집합 지정 <-- 그렇지만 안됨
			in = new InputStreamReader(fin = 
					new FileInputStream("C:/Users/user/Desktop/8장_강의자료"
							+ "/8장_source/8장/chap08-ex02/src/hangul.txt"),"UTF-8");
			int c;

			System.out.println("인코딩 문자 집합은 " + in.getEncoding());
			while ((c = in.read()) != -1) {
				System.out.print((char)c);
			}
			in.close();
			fin.close();
		} catch (IOException e) {
			System.out.println("입출력 오류");
		}
	}
}
