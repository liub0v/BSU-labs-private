import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//public class MyNotebook extends JFrame implements ActionListener{
    public class MyNotebook extends JFrame {
    private JTextField tf;
    private JTextArea ta;

    MyNotebook(String title)
    {
        super(title);
        Container con=getContentPane();
        tf=new JTextField("Enter text...",50);
        con.add(tf,BorderLayout.NORTH);

        ta=new JTextArea();
        ta.setEnabled(false);//нельзя вводить текст
        con.add(ta);

        JPanel p=new JPanel();
        con.add(p,BorderLayout.SOUTH);

        JButton b=new JButton("add next");
        p.add(b);

        //tf.addActionListener(this);
        //b.addActionListener(this);
       //tf.addActionListener(new TextMove());
       //b.addActionListener(new TextMove());

        tf.addActionListener(new MyClass(tf,ta));
        b.addActionListener(new MyClass(tf,ta));

        setSize(300,200);
        setVisible(true);
    }
    //1ой способ
   /* public void actionPerformed(ActionEvent e)//добавляет текст в поле
    {
        ta.append(tf.getText()+"\n");
    }*/

    public static void main(String[] args) {
        JFrame f =new  MyNotebook("Обрабобтка ActionEvent");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//выйти по закрытию
    }
    //2ой способ
   /* class TextMove implements ActionListener
    {
        public void actionPerformed(ActionEvent e)//добавляет текст в поле
        {
            ta.append(tf.getText()+"\n");
        }
    }*/
}
