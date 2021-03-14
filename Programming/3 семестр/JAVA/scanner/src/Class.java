import java.util.*;
import java.util.ArrayList.*;
import java.io.File.*;
import  java.io.File;
import  java.util.regex.*;
public class Class {
    Scanner input = new Scanner("C:\\Users\\User\\IdeaProjects\\scanner\\input\\file.txt");
    ArrayList lines = new ArrayList();
    File file = new File(input.nextLine());

    public ArrayList readFromFile() {
        int i = 0;
        try {
            //System.out.print("Enter the file name with extension : ");
            input = new Scanner(file);

            while (input.hasNextLine()) {
                String line = input.nextLine();
                lines.add(line);
                //System.out.println(line);
                i++;
            }
            //System.out.println(lines);

        } catch (Exception ex) {
            ex.printStackTrace();
        }
        input.close();
        return lines;
    }
    public void delete(ArrayList arrayList)
    {
        int size =arrayList.size();

        for(int i=0;i<size;i++)
        {
            StringBuilder sb=new StringBuilder(arrayList.get(i).toString());
            Pattern p = Pattern.compile("\\([^)]+\\)");
            Matcher m = p.matcher(sb);
            System.out.println(m.replaceAll(""));
            //System.out.println(arrayList.get(i).toString().replaceAll("\\([^)]+\\)", ""));
        }
    }


}
