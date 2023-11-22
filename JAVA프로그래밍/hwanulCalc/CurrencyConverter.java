package hwanulCalc; // 패키지 분류 선언

import javax.swing.*; // swing gui 사용시 선언
import java.awt.*;
import java.awt.event.ActionEvent; // 사용자의 액션(예: 버튼 클릭, 키 입력)에 응답하는 이벤트
import java.awt.event.ActionListener; // 액션 이벤트에 대한 리스너 인터페이스


public class CurrencyConverter extends JFrame 
{
    private JTextField txtKRW; // 원화 입력창
    private JButton convertButton; // 번환 버튼
    private JLabel resultLabel; // 결과 출력 라벨
    private JComboBox<String> currencySelector; // 변환할 통화 선택하는 박스 

    public CurrencyConverter() 
    {
        setTitle("KRW to USD/JPY Converter");
        Container c = getContentPane();
        c.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40)); // 레이아웃 매니저를 사용하지 않고, 수동으로 각 구성 요소의 위치와 크기를 설정함
        setSize(400, 200);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        

        txtKRW = new JTextField(10); // 한화 입력 박스 생성
        txtKRW.setBounds(20, 20, 100, 30); // 위치와 크기 지정
        c.add(txtKRW); // 박스를 프레임에 추가

        String[] currencies = {"USD", "JPY"};
        currencySelector = new JComboBox<>(currencies); // 통화 선택 박스 생성
        currencySelector.setBounds(140, 20, 100, 30); // 각각 x, y, width, height를 입력하여 
        											  // 위치와 크기를 받음
        c.add(currencySelector); // 통화 선택 박스 추가

        convertButton = new JButton("Convert"); // 변환 버튼 생성 
        convertButton.setBounds(260, 20, 100, 30); // 위치와 크기 지정
        c.add(convertButton); // 버튼 추가

        resultLabel = new JLabel("Result"); // 결과 출력 라벨 생성
        resultLabel.setBounds(20, 70, 340, 30); // 위치와 크기 지정
        c.add(resultLabel); // 라벨 추가

        convertButton.addActionListener(new ActionListener() 
        { // 버튼에 액션 리스너 추가
            @Override
            public void actionPerformed(ActionEvent e) // 버튼이 눌렸을때 실행할 코드 정의
            {
                double krw = Double.parseDouble(txtKRW.getText()); // 입력받은 한화를 double로 parse한 뒤
                												   // 변수에 저장
                String selectedCurrency = (String) currencySelector.getSelectedItem(); // 선택한 통화를
                										// 문자열로 바꾼뒤 변수에 저장
                double result; // 결과 저장 변수 선언

                if ("USD".equals(selectedCurrency)) // 선택한 통화가 달러일때
                {
                    // 환율: 1 KRW = 0.00077 USD로 지정
                    result = krw * 0.00077; // 2023/11/22 기준
                    resultLabel.setText(krw + " KRW = " + result + " USD"); // 변환 후 라벨에 출력
                } 
                
                else if ("JPY".equals(selectedCurrency)) // 선택한 통화가 일본 엔화 일때
                {
                    // 환율: 1 KRW = 0.094 JPY로 지정
                    result = krw * 0.094; // 2023/11/22 기준
                    resultLabel.setText(krw + " KRW = " + result + " JPY"); // 변환 후 라벨에 출력
                }
            }
        });
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(new Runnable() // GUI 생성 이벤트 종료 후 해당 객체가 실행되도록 예약
        {
            @Override
            public void run() // 실제로 수행하려는 작업 정의
            {
                new CurrencyConverter();
            }
        });
    }
}