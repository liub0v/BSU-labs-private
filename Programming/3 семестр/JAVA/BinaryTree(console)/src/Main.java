import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main{
    public static void main(String[] args) {

       // Tree<Integer> tree = new Tree<>(6, null);
        //tree.add(3,7,2,5,9);
        Tree<Person> personTree;
        Person p1=new Person("Person1","170");
        Person p2=new Person("Person2","180");
        Person p3=new Person("Person3","190");
        Person p4=new Person("Person4","150");
        personTree=new Tree<Person>(p1,null);
        personTree.add(p2,p3,p4);
        personTree.search(p2).print();
        personTree.print();
        String str="";
        for(int i=0;i<personTree.getListForPrint().size();i++) {
            str+=personTree.getListForPrint().get(i).toString()+" ";
        }
        System.out.println(str);
        str="";
        //personTree.remove(p4);
        personTree.remove(p2);
        //personTree.remove(p3);
        for(int i=0;i<personTree.getListForPrint().size();i++) {
            str+=personTree.getListForPrint().get(i).toString()+" ";
        }
        System.out.println(str);
        JFrame frame =new TreeForm<>();
        frame.setSize(400,400);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    }
}
