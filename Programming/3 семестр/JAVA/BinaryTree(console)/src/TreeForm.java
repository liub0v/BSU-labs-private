import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TreeForm<T> extends JFrame {
    private JTextField textField1;
    private JButton addButton;
    private JPanel panel1;
    private JButton deleteButton;
    private JButton treeButton;
    private JTextArea textArea1;
    private JTextArea textArea2;
    private JTextField textField2;
    private JButton enterRootButton;
    private JButton sumButton;
    private JComboBox comboBox1;

    public TreeForm(T val)
    {

    }


    public JTextArea getTextArea1()
    {
        return textArea1;
    }
    Tree<Integer> tree1;
    Tree<Person> personTree;
    Person personRoot=new Person();
    Person personTop=new Person();
    int ver=0;

    public TreeForm(){
        super("Binary Tree");
        setContentPane(panel1);
        enterRootButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                //String[] strings=str.split(" ");
               // personRoot.setName(strings[0]);
                //personRoot.setHeight(Integer.parseInt(strings[1]));
                int root=Integer.parseInt(textField2.getText());
                tree1=new Tree<Integer>(root,null);
                //personTree=new Tree<Person>(personRoot,null);
                textField2.setText("");
                textArea1.setText("Root: "+ root);
            }
        });
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //textArea1.setText(textField1.getText()+"\n");
                /*String str=textField1.getText();
                String[] strings=str.split(" ");
                personTop.setName(strings[0]);
                personTop.setHeight(Integer.parseInt(strings[1]));*/
                ver=Integer.parseInt(textField1.getText());
                tree1.add(ver);
                //personTree.add(personTop);
                textField1.setText("");
                textArea1.setText("New graph vertex: "+ver);
            }
        });

        treeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tree1.print();
                String str="";
                for(int i=0;i<tree1.getListForPrint().size();i++) {
                    str+=tree1.getListForPrint().get(i).toString()+" ";
                }
                textArea2.setText("Tree: "+str);
            }
        });

        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ver=Integer.parseInt(textField1.getText());
                tree1.remove(ver);
                textField1.setText("");
                textArea1.setText("Deleted graph vertex: "+ver);
            }
        });

        sumButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int Sum=0;
                for(int i=0;i<tree1.getListForPrint().size();i++) {
                    Sum+=tree1.getListForPrint().get(i);
                }
                textArea2.setText("Sum: "+Sum);
            }
        });

        comboBox1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                switch (comboBox1.getSelectedItem().toString()) {

                    case "PreOrder":
                        String str="";
                        tree1.recPreOrder(tree1);
                        for(int i=0;i<tree1.getListForPrint().size();i++) {
                            str+=tree1.getListForPrint().get(i).toString()+" ";
                        }
                        textArea2.setText("Tree: "+str);
                        tree1.getListForPrint().clear();
                        break;
                    case "InOrder":
                        String str1="";
                        tree1.recInOrder(tree1);
                        for(int i=0;i<tree1.getListForPrint().size();i++) {
                            str1+=tree1.getListForPrint().get(i).toString()+" ";
                        }
                        textArea2.setText("Tree: "+str1);
                        tree1.getListForPrint().clear();
                        break;
                    case "PostOrder":
                        String str2="";
                        tree1.recPostOrder(tree1);
                        for(int i=0;i<tree1.getListForPrint().size();i++) {
                            str2+=tree1.getListForPrint().get(i).toString()+" ";
                        }
                        textArea2.setText("Tree: "+str2);
                        tree1.getListForPrint().clear();
                        break;

                }

            }
        });

    }

    private void createUIComponents() {
        // TODO: place custom component creation code here
    }
}