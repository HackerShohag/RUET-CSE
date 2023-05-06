import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;

public class MySimpleCalculator extends JFrame implements ActionListener {
    private String preedit = "", prevString = "", currentOperation = "";
    boolean multipleOpearations = false;
    static double result = 0;
    Container c = new Container();
    JPanel panel = new JPanel();
    JPanel buttonContainer = new JPanel();
    JLabel display = new JLabel("CALCULATE", SwingConstants.RIGHT);
    JLabel displaySign = new JLabel("", SwingConstants.LEFT);

    JButton []button = new JButton[16];
    String []items = {"-", "+", "="};
    Font defaultFont = new Font("DigiFace",Font.PLAIN,50);
    MySimpleCalculator(String title) {
        // JFrame config
        this.setTitle(title);
        this.setVisible(true);
        this.setBounds(1500, 150, 290, 500);
//        this.setResizable(false);

        // container config
        c.setBounds(10, 10,280, 490);
        c.setVisible(true);
        this.add(c);

        // panel config
        panel.setBounds(10, 10, 270, 50);
        panel.setLayout(null);
        panel.setBackground(Color.lightGray);
        panel.add(display);
        panel.add(displaySign);

        // buttonContainer configs
        buttonContainer.setBounds(10, 65, 270, 390);
        buttonContainer.setBackground(Color.lightGray);

        // label configs
        displaySign.setBounds(10, 2, 40, 50);
        displaySign.setFont(new Font("DigiFace",Font.PLAIN,30));
        displaySign.setForeground(Color.RED);
//        displaySign.setText("/");

        display.setBounds(50, 2, 220, 50);
        display.setFont(defaultFont);
        display.setForeground(Color.BLACK);

        // buttons section
        // first row
        for (int i = 7; i < 10; i++) {
            JButton btn = new JButton(String.valueOf(i));
            btn.setFont(defaultFont);
            btn.addActionListener(this);
            button[i] = btn;
            buttonContainer.add(button[i]);
        }
        button[15] = new JButton("C");
        button[15].setFont(defaultFont);
        button[15].addActionListener(this);
        buttonContainer.add(button[15]);

        // second row
        for (int i = 4; i < 7; i++) {
            JButton btn = new JButton(String.valueOf(i));
            btn.setFont(defaultFont);
            btn.addActionListener(this);
            button[i] = btn;
            buttonContainer.add(button[i]);
        }

        button[14] = new JButton("/");
        button[14].setFont(defaultFont);
        button[14].addActionListener(this);
        buttonContainer.add(button[14]);

        // third row
        for (int i = 1; i < 4; i++) {
            JButton btn = new JButton(String.valueOf(i));
            btn.setFont(defaultFont);
            btn.addActionListener(this);
            button[i] = btn;
            buttonContainer.add(button[i]);
        }
        button[13] = new JButton("x");
        button[13].setFont(defaultFont);
        button[13].addActionListener(this);
        buttonContainer.add(button[13]);

        // zero button
        button[0] = new JButton("0");
        button[0].setFont(defaultFont);
        button[0].addActionListener(this);
        buttonContainer.add(button[0]);

        // forth row
        for (int i = 10; i < 13; i++) {
            JButton btn = new JButton(items[i-10]);
            btn.setFont(defaultFont);
            btn.addActionListener(this);
            button[i] = btn;
            buttonContainer.add(button[i]);
        }
        // adding section
        c.add(panel);
        c.add(buttonContainer);

    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {

        // handling zero
        if (actionEvent.getSource() == button[0]) {
            if (Objects.equals(displaySign.getText(), "=")) {setPreedit("");}
            if (Objects.equals(getPreedit(), "")) {
                display.setText("0");
            } else {
                setPreedit(getPreedit() + button[0].getText());
                display.setText(getPreedit());
            }
            displaySign.setText("");
        }
        // handling one to nine
        for (int i = 1; i < 10; i++) {
            if (actionEvent.getSource() == button[i]) {
                if (Objects.equals(displaySign.getText(), "=")) {setPreedit("");}
                setPreedit(getPreedit() + button[i].getText());
                display.setText(getPreedit());
                displaySign.setText("");
            }
        }
        // handling operations
        // for subtraction operation
        if (actionEvent.getSource() == button[10]) {
            displaySign.setText(button[10].getText());
            if (multipleOpearations) {
                setPrevString(Double.toString(doCalculation(Double.parseDouble(getPrevString()), Double.parseDouble(getPreedit()), getOperation())));
            }
            else {
                setPrevString(getPreedit());
            }
            setPreedit("");
            setOperation(displaySign.getText());
            multipleOpearations = true;
        }
        // for addition operation
        if (actionEvent.getSource() == button[11]) {
            displaySign.setText(button[11].getText());
            if (multipleOpearations) {
                setPrevString(Double.toString(doCalculation(Double.parseDouble(getPrevString()), Double.parseDouble(getPreedit()), getOperation())));
            }
            else {
                setPrevString(getPreedit());
            }
            setPreedit("");
            setOperation(displaySign.getText());
            multipleOpearations = true;
        }
        // for multiplication operation
        if (actionEvent.getSource() == button[13]) {
            displaySign.setText(button[13].getText());
            if (multipleOpearations) {
                setPrevString(Double.toString(doCalculation(Double.parseDouble(getPrevString()), Double.parseDouble(getPreedit()), getOperation())));
            }
            else {
                setPrevString(getPreedit());
            }
            setPreedit("");
            setOperation(displaySign.getText());
            multipleOpearations = true;
        }
        // for division operation
        if (actionEvent.getSource() == button[14]) {
            displaySign.setText(button[14].getText());
            if (multipleOpearations) {
                setPrevString(Double.toString(doCalculation(Double.parseDouble(getPrevString()), Double.parseDouble(getPreedit()), getOperation())));
            }
            else {
                setPrevString(getPreedit());
            }
            setPreedit("");
            setOperation(displaySign.getText());
            multipleOpearations = true;
        }

        // handling clear button
        if (actionEvent.getSource() == button[15]) {
            setPreedit("");
            setPrevString("");
            result = 0;
            display.setText("0");
            displaySign.setText("");
            multipleOpearations = false;
        }
        // handling equal button
        if (actionEvent.getSource() == button[12]) {
            displaySign.setText(button[12].getText());
            result = doCalculation(Double.parseDouble(getPrevString()), Double.parseDouble(getPreedit()), getOperation());
            display.setText(Double.toString(result));
            setPreedit(Double.toString(result));
//            setPrevString("");
//            setOperation("");
            multipleOpearations = false;
        }
    }
    double doCalculation(double prev, double next, String cOperation) {
        double res = 0;
        if (Objects.equals(cOperation, "-")){
            res = prev - next;
        }
        if (Objects.equals(cOperation, "+")) {
            res = prev + next;
        }
        if (Objects.equals(cOperation, "x")) {
            res = prev * next;
        }
        if (Objects.equals(cOperation, "/")) {
            res = prev / next;
        }
        return res;
    }

    public void setPreedit(String preedit) {
        this.preedit = preedit;
    }
    public String getPreedit() {
        return this.preedit;
    }
    public void setPrevString(String prevString) {
        this.prevString = prevString;
    }
    public String getPrevString() {
        return this.prevString;
    }
    public void setOperation(String operation) {
        this.currentOperation = operation;
    }
    public String getOperation() {
        return this.currentOperation;
    }
}
