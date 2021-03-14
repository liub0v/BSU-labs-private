import java.util.ArrayList;

public class Main  {

    public static void main(String[] args) {

        Class ob=new Class();

        ArrayList lines=new ArrayList();
        lines=ob.readFromFile();
        //System.out.println(lines);
        //System.out.println();
        System.out.println(lines);
        ob.delete(lines);
        lines.clear();



    }
}
