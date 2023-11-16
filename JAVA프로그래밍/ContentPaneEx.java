package ContentPane;
import javax.swing.*;
import java.awt.*;

public class ContentPaneEx extends JFrame
{
	public ContentPaneEx()
	{
		setTitle("ContentPane과 JFrame 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// 프레임 윈도우를 닫으면 프로그램을 종료하도록 설정
		
		Container contentpane = getContentPane(); // 컨텐트팬 알아내기
		contentpane.setBackground(Color.ORANGE); // 오렌지색 배경 설정
		contentpane.setLayout(new FlowLayout()); // 컨텐트팬에 FlowLayout 배치 관리자 달기
		
		contentpane.add(new JButton("OK")); // OK버튼 달기
		contentpane.add(new JButton("Cancel")); // Cancel버튼 달기
		contentpane.add(new JButton("Ignore")); // Ignore버튼 달기
		
		setSize(300, 150); // 프레임 사이즈 설정
		setVisible(true); // 화면에 프레임 출력
	}
	
	public static void main(String[] args)
	{
		new ContentPaneEx();
	}
}
