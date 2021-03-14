import java.io.File;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner scanner1=null;
        Scanner scanner2=null;
        try {
            MyContainer<ForestTree> fruitTree = new MyContainer<>();
            MyContainer<FruitTree> forestTree = new MyContainer<>();
            scanner1 = new Scanner(new File("input1.txt"));
            while (scanner1.hasNext())
                fruitTree.add(new ForestTree(scanner1.next(), scanner1.nextInt(), Tree.Type.valueOf(scanner1.next().toUpperCase()), scanner1.nextInt()));
            scanner2 = new Scanner(new File("input2.txt"));
            while (scanner2.hasNext())
                forestTree.add(new FruitTree(scanner2.next(),scanner2.nextInt(), Tree.Type.valueOf(scanner2.next()),scanner2.nextInt()));

            System.out.println("Count: "+ fruitTree.count(fruitTree.get(0)));
            System.out.println("SUM: "+fruitTree.sum(Tree.Type.CONIFER));
            System.out.println("________MIN_________\n "+fruitTree.min());
            System.out.println("_________INFO_______");
            Comparator<ForestTree> fruitTreeComparator=new ForestComporator();
            fruitTree.information_sorted(fruitTreeComparator);
            System.out.println("-----------------------");
            System.out.println("Count: "+forestTree.count(forestTree.get(1)));
            System.out.println("SUM: "+forestTree.sum(Tree.Type.DECIDUOUS));
            System.out.println("_________MIN________\n"+forestTree.min());
            System.out.println("_________INFO_______");
            Comparator<FruitTree> forestTreeComparator=new FruitComparator();
            forestTree.information_sorted(forestTreeComparator);

        }catch (FileNotFoundException e) {
            System.out.println(e);
        }catch (InputMismatchException e) {
            System.out.println("INCORRECT ENTRY");
        }catch (MyException e) {
            System.out.println(e.getMessage());
            return;
        }finally {
            if(scanner1!=null)
                scanner1.close();
            if(scanner2!=null)
                scanner2.close();
        }

    }

}
