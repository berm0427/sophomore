import java.io.*;
import java.util.*;

public class FileWriterEx {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); 
		//FileWriter fout = null;
		
		try {
			FileWriter fout = new FileWriter("C:\\Users\\user\\Desktop\\8장_강의자료\\8장_source\\8장\\chap08-ex04\\src\\test.txt"); // 파일과 연결된 출력 문자 스트림 생성
			while(true) {
				String line = scanner.nextLine();
				if(line.length() == 0) // 한 줄에 <Enter>키만 입력한 경우
					break;
				fout.write(line, 0, line.length()); 
				// fout.write("\r\n", 0, 2); // \r\n을 파일에 기록
				// fout.write("\n");
				// fout.write("\r");
			}
			fout.close();
		} 
		catch (FileNotFoundException e) {
			System.out.println("File is not found");
		}
		catch (IOException e) {
			System.out.println("입출력 오류");
		}
		scanner.close();
	}
}