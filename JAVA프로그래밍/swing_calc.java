/* package swing;
import javax.swing.*;
import java.awt.*;

public class swing_calc extends JFrame
{
	public swing_calc()
	{
		setTitle("계산기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		c.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40));
		c.add(new JButton("add"));
		c.add(new JButton("sub"));
		c.add(new JButton("mul"));
		c.add(new JButton("div"));
		c.add(new JButton("Calculate"));
		
		setSize(350, 200);
		setVisible(true);
	}
	
	public static void main(String[] args)
	{
		new swing_calc();
	}
}
*/
package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class swing_calc extends JFrame {
    private JTextField inputField;
    private double result;
    private String operator;
    private boolean startOfNumber;

    public swing_calc() {
        setTitle("계산기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new BorderLayout());

        inputField = new JTextField(""); // 입력 필드에 시작으로 들어있는 값
        inputField.setHorizontalAlignment(JTextField.RIGHT); // 입력 커서 오른쪽 정렬
        c.add(inputField, BorderLayout.NORTH); // 맨 위에 입력 필드 놓기

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 5, 5)); // 4 x 3 배치, 수직 간격 5픽셀, 수평 간격 5픽셀 배치

        ActionListener insert = new InsertAction();
        ActionListener command = new CommandAction();

        addButton(buttonPanel, "7", insert);
        addButton(buttonPanel, "8", insert);
        addButton(buttonPanel, "9", insert);
        addButton(buttonPanel, "/", command);

        addButton(buttonPanel, "4", insert);
        addButton(buttonPanel, "5", insert);
        addButton(buttonPanel, "6", insert);
        addButton(buttonPanel, "*", command);

        addButton(buttonPanel, "1", insert);
        addButton(buttonPanel, "2", insert);
        addButton(buttonPanel, "3", insert);
        addButton(buttonPanel, "-", command);

        addButton(buttonPanel, "0", insert);
        addButton(buttonPanel, ".", insert);
        addButton(buttonPanel, "=", command);
        addButton(buttonPanel, "+", command);

        c.add(buttonPanel, BorderLayout.CENTER);

        startOfNumber = true;
        operator = "=";
        result = 0;

        setSize(350, 200);
        setVisible(true);
    }

    private void addButton(Container c, String text, ActionListener listener) {
        JButton button = new JButton(text);
        c.add(button);
        button.addActionListener(listener);
    }

    private class InsertAction implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            String input = event.getActionCommand();
            if (startOfNumber) {
                inputField.setText("");
                startOfNumber = false;
            }
            inputField.setText(inputField.getText() + input);
        }
    }

    private class CommandAction implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            String command = event.getActionCommand();

            if (startOfNumber) {
                if (command.equals("-")) {
                    inputField.setText(command);
                    startOfNumber = false;
                } else {
                    operator = command;
                }
            } else {
                calculate(Double.parseDouble(inputField.getText()));
                operator = command;
                startOfNumber = true;
            }
        }
    }

    public void calculate(double x) {
        switch (operator) {
            case "+": result += x; break;
            case "-": result -= x; break;
            case "*": result *= x; break;
            case "/": result /= x; break;
            case "=": result = x; break;
        }
        inputField.setText("" + result);
    }

    public static void main(String[] args) {
        new swing_calc();
    }
}
