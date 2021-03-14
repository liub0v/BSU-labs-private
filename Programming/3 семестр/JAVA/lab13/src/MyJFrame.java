import java.awt.List;
import java.io.*;
import java.awt.event.*;
import java.awt.*;
import java.text.Format;
import java.util.*;
import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.filechooser.FileNameExtensionFilter;

public class MyJFrame extends JFrame implements ActionListener {
    public static void main(String[] args) {
        new MyJFrame("Students");
    }

    protected static JLabel empty = new JLabel("");
    private JButton show = new JButton("    Sort    ");
    private JButton add = new JButton("    Add     ");
    private JButton saveXML = new JButton("Save xml");
    private JButton readXML = new JButton("Read xml");
    private List list = new List();
    private List list2 = new List();
    private ArrayList<Student> a;
    private JMenuBar menuBar;
    private JMenu menu;
    private JMenuItem menuItem;

    public MyJFrame(String title) {
        super(title);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setResizable(false);

        menuBar = new JMenuBar();
        menu = new JMenu("File");

        menuItem = new JMenuItem("Open");
        menuItem.setMnemonic(KeyEvent.VK_O);
        menuItem.addActionListener(this);
        menu.add(menuItem);
        menuBar.add(menu);
        setJMenuBar(menuBar);

        Container container = this.getContentPane();
        container.setLayout(new BoxLayout(container, 2));
        JPanel jPanel = new JPanel();

        Box b = new Box(2);
        b.add(jPanel);
        b.add(list);
        b.add(list2);
        container.add(b);

        Box b2 = new Box(1);
        show.addActionListener(this);
        JPanel jPanel1 = new JPanel();
        jPanel1.add(show);
        b2.add(jPanel1);

        add.addActionListener(this);
        JPanel jPanel3 = new JPanel();
        jPanel3.add(add);
        b2.add(jPanel3);

        saveXML.addActionListener(this);
        JPanel jPanel2=new JPanel();
        jPanel2.add(saveXML);
        b2.add(jPanel2);

        readXML.addActionListener(this);
        JPanel jPanel4=new JPanel();
        jPanel4.add(readXML);
        b2.add(jPanel4);

        container.add(b2);

        read("data.txt");
        show(list, a);
        setSize(700, 250);
        //pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == show) {
            show(list, a);
            TreeSet<Student> set = new TreeSet<>(new MyComparator());
            Iterator<Student> iterator = a.iterator();
            while (iterator.hasNext()) {
                Student student=iterator.next();
                int temp=Integer.parseInt(student.getMark());
                if(temp>8)
                    set.add(student);
            }
            show(list2, set);
        } else if (e.getSource() == menuItem) {
            JFileChooser chooser = new JFileChooser();
            FileNameExtensionFilter filter = new FileNameExtensionFilter("Text files", "txt");
            chooser.setFileFilter(filter);
            File workingDirectory = new File(System.getProperty("user.dir"));
            chooser.setCurrentDirectory(workingDirectory);
            if (chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
                read(chooser.getSelectedFile().getName());
                show(list, a);
                list2.removeAll();
            }

        } else if (e.getSource() == add) {
            Student tempStudent = new Student();
            new EditJDialog(this, "NEW STUDENT", tempStudent);

            if (!tempStudent.equals(new Student())) {
                a.add(tempStudent);
                show(list, a);
            }
        }else if(e.getSource()==saveXML){
            XMLSample xml_save=new XMLSample();
            xml_save.writeDataXML(a);

        }else if(e.getSource()==readXML){
            XMLSample xml_read=new XMLSample();

            show(list2, xml_read.readDataXML());
            System.out.println(xml_read.readDataXML());
        }
    }

    private void read(String filename) {
        Scanner sc = null;
        try {
            sc = new Scanner(new FileReader(filename));
            a = new ArrayList<>();
            while (sc.hasNext())
                a.add(new Student(sc.next(), sc.next(), sc.next(), sc.next()));
        } catch (FileNotFoundException err) {
            JOptionPane.showMessageDialog(this, err, "Error!", JOptionPane.PLAIN_MESSAGE);
        } finally {
            if (sc != null)
                sc.close();
        }
    }

    private void show(List list, Collection<Student> a) {
        if (a != null) {
            list.removeAll();
            Iterator<Student> iterator=a.iterator();
            while(iterator.hasNext())
                list.add(iterator.next().toString());
        } else {
            JOptionPane.showMessageDialog(this, "There are no elements!", "Error!", JOptionPane.PLAIN_MESSAGE);
        }

    }
}