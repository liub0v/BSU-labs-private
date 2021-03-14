import java.awt.event.*;
import java.awt.*;
import java.util.zip.DataFormatException;
import javax.swing.*;

public class EditJDialog extends JDialog implements ActionListener {
    private JButton ok = new JButton("OK");
    private JLabel labelNumber = new JLabel("  NUMBER:");
    private JLabel labelName = new JLabel("  NAME:");
    private JLabel labelSubject = new JLabel("  SUBJECT:");
    private JLabel labelMark = new JLabel("  RATING:");
    private JTextField inputName = new JTextField("", 4);
    private JTextField inputNumber = new JTextField("", 4);
    private JTextField inputSubject = new JTextField("", 4);
    private JTextField inputMark = new JTextField("", 4);
    private Student student;

    public EditJDialog(JFrame parent, String title, Student o) {
        super(parent, title, true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        //setResizable(false);
        this.student = o;

        Container container = this.getContentPane();
        container.setLayout(new GridLayout(5, 2));

        container.add(labelNumber);
        inputNumber.setText(student.getNumber());
        container.add(inputNumber);

        container.add(labelName);
        inputName.setText(student.getName() + "");
        container.add(inputName);

        container.add(labelSubject);
        inputSubject.setText(student.getSubject() + "");
        container.add(inputSubject);

        container.add(labelMark);
        inputMark.setText(student.getMark() + "");
        container.add(inputMark);

        container.add(MyJFrame.empty);
        ok.addActionListener(this);
        container.add(ok);
        setSize(300,250);
        //pack();
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ok) {
            try {
                if (inputNumber.getText().equals(""))
                    throw new DataFormatException("Set name!");
                student.setName(inputName.getText());
                student.setNumber(inputNumber.getText());
                student.setSubject(inputSubject.getText());
                student.setMark(inputMark.getText());
                setVisible(false);   // это норма?
            } catch (NumberFormatException err) {
                JOptionPane.showMessageDialog(this, err, "Error!", JOptionPane.PLAIN_MESSAGE);
            } catch (DataFormatException err) {
                JOptionPane.showMessageDialog(this, err.getMessage(), "Error!", JOptionPane.PLAIN_MESSAGE);
            }
        }
    }
}