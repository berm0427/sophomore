package swing_calc;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class swing_calc_with_history extends JFrame {
    private JTextField inputField;
    private JTextArea historyArea;
    private ArrayList<String> history;
    private double result;
    private String operator;
    private boolean startOfNumber;
    private String currentCalculation;

    public swing_calc_with_history() {
        setTitle("계산기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new BorderLayout());

        inputField = new JTextField("");
        inputField.setHorizontalAlignment(JTextField.RIGHT);
        c.add(inputField, BorderLayout.NORTH);

        history = new ArrayList<>();
        historyArea = new JTextArea(10, 10);
        historyArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(historyArea);
        c.add(scrollPane, BorderLayout.EAST);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 5, 5));

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
        currentCalculation = "";

        setSize(500, 300);
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
            if (currentCalculation.isEmpty() || operator.equals("=")) {
                currentCalculation = inputField.getText();
            } else {
                currentCalculation += input;
            }
        }
    }

    private class CommandAction implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            String command = event.getActionCommand();

            if (startOfNumber) {
                if (command.equals("-")) {
                    inputField.setText(command);
                    startOfNumber = false;
                    currentCalculation = command;
                } else {
                    operator = command;
                }
            } else {
                double x = Double.parseDouble(inputField.getText());
                calculate(x);
                if (command.equals("=")) {
                    history.add(currentCalculation + " = " + result);
                    updateHistory();
                    currentCalculation = "";
                } else {
                    currentCalculation += " " + command + " ";
                }
                inputField.setText("");
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

    private void updateHistory() {
        StringBuilder sb = new StringBuilder();
        for (String record : history) {
            sb.append(record).append("\n");
        }
        historyArea.setText(sb.toString());
    }

    public static void main(String[] args) {
        new swing_calc_with_history();
    }
}
