import java.io.*;

public class FileOutputStreamEx {
	public static void main(String[] args) {
		byte b[] = {7,51,3,4,-1,24};
		String d = "C:\\Users\\user\\Desktop\\8장_강의자료\\8장_source\\8장\\chap08-ex05\\src\\test.out";
		try { 
			FileOutputStream fout = new FileOutputStream(d);
			for(int i=0; i<b.length; i++)
				fout.write(b[i]); // 배열 b의 바이너리를 그대로 기록
			fout.close();
		} catch(IOException e) {
			System.out.println(d + "에 저장할 수 없었습니다. 경로명을  확인해 주세요");
			return;
		}
		System.out.println(d + "을 저장하였습니다.");
	}
}