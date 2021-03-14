import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.*;

public class MyJFrame extends JFrame {
    public MyJFrame(String title)
    {
        super(title);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JTabbedPane tabbedPane=new JTabbedPane();
        //tabbedPane.addTab("Task1",new ImageIcon(),new Card1(),"Lists");
        tabbedPane.addTab("Task1",new ImageIcon(),new Card1(),"Lists");
        tabbedPane.setMnemonicAt(0, KeyEvent.VK_1);
        tabbedPane.addTab("Task2",new ImageIcon(),new Card2(),"Lists");
        tabbedPane.setMnemonicAt(0, KeyEvent.VK_2);

        add(tabbedPane);
        pack();
        setVisible(true);
    }

    class Card1 extends JPanel
    {
        public Card1()
        {
            setLayout(new BorderLayout());
            JPanel central=new JPanel();
            central.setLayout(new BorderLayout());

            //JButton right = new JButton(new ImageIcon("s2.png"));
            JButton right = new JButton(">>>>>>>");
            central.add(right,BorderLayout.NORTH);
            JButton left = new JButton("<<<<<<<");
            central.add(left,BorderLayout.SOUTH);
            add(central,BorderLayout.CENTER);

            final String[] strings1={"String1","String3","String5","String7","String9","String11","String13","String15"};
            final String[] strings2={"String2","String4","String6","String8","String10","String12","String14","String16","String18"};

            DefaultListModel leftListModel=new DefaultListModel();
            JList leftList = new JList(leftListModel);
            leftList.setFont(new Font(getFont().getFontName(), Font.TYPE1_FONT, 30));
            DefaultListModel rightListModel=new DefaultListModel();
            JList rightList = new JList(rightListModel);
            rightList.setFont(new Font(getFont().getFontName(), Font.TYPE1_FONT, 30));

            for(String i: strings1)
                leftListModel.addElement(i);
            for(String i:strings2)
                rightListModel.addElement(i);

            add(leftList,BorderLayout.WEST);
            add(new JScrollPane(leftList,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                    JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.WEST);

            add(rightList,BorderLayout.EAST);
            add(new JScrollPane(rightList,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                    JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.EAST);

            right.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent actionEvent) {
                    if(!leftList.isSelectionEmpty())
                    {
                        rightListModel.addElement(leftList.getSelectedValue());
                        leftListModel.remove(leftList.getSelectedIndex());
                        if(!leftListModel.isEmpty())
                            leftList.setSelectedIndex(0);
                    }
                }
            });
            left.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent actionEvent) {
                    if(!rightList.isSelectionEmpty())
                    {
                        leftListModel.addElement(rightList.getSelectedValue());
                        rightListModel.remove(rightList.getSelectedIndex());
                        if(!rightListModel.isEmpty())
                            rightList.setSelectedIndex(0);
                    }
                }
            });
            pack();

        }
    }
     class Card2 extends JPanel
     {
         public Card2()
         {
             Box box=new Box(1);
             ButtonGroup radioGroup=new ButtonGroup();
             final ImageIcon[] icons=new ImageIcon[]
                     {
                             new ImageIcon("1.png"), new ImageIcon("2.png"),
                             new ImageIcon("3.png"),new ImageIcon("4.png"),
                     };
             for(int i=0;i<3;i++)
             {
                 JRadioButton temp=new JRadioButton(icons[0]);
                 temp.setPressedIcon(icons[1]);
                 temp.setRolloverIcon(icons[2]);
                 temp.setSelectedIcon(icons[3]);
                 radioGroup.add(temp);
                 box.add(temp);
             }
             add(box);
         }
     }
}
