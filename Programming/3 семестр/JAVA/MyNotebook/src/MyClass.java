import java.awt.event.ActionListener;
import javax.swing.*;
import java.awt.event.*;

public class MyClass implements ActionListener {

    private JTextField tf;
    private JTextArea ta;
    MyClass(JTextField tf,JTextArea ta)
    {
        this.tf=tf;
        this.ta=ta;
    }
    public void actionPerformed(ActionEvent e)//добавляет текст в поле
    {
        ta.append(tf.getText()+"\n");
    }
}
