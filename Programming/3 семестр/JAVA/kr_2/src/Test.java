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
            MyContainer<Pupil> pupilMyContainer = new MyContainer<>();
            MyContainer<Student> studentMyContainer = new MyContainer<>();
            Learner learner;
            scanner1 = new Scanner(new File("input1.txt"));
            while (scanner1.hasNext())
                pupilMyContainer.add(new Pupil(scanner1.next(), scanner1.next(), scanner1.nextInt(),scanner1.nextInt(),Pupil.Behavior.valueOf(scanner1.next().toUpperCase())));
            scanner2 = new Scanner(new File("input2.txt"));
            while (scanner2.hasNext())
                studentMyContainer.add(new Student(scanner2.next(),scanner2.next(),scanner2.nextInt(), scanner2.nextInt()));

            System.out.println("Count: "+ pupilMyContainer.count(pupilMyContainer.get(1)));
            System.out.println("Average of school: "+pupilMyContainer.average("School1"));
            System.out.println("___________MIN______________\n "+pupilMyContainer.min());
            System.out.println("____________INFO____________\n");
            Comparator<Pupil> pupilComparator=new StudentComporator();
            pupilMyContainer.print(pupilComparator);

            System.out.println("-----------------------");
            System.out.println("Count: "+studentMyContainer.count(studentMyContainer.get(0)));
            System.out.println("Average of university: "+studentMyContainer.average("Harvard"));
            System.out.println("___________MIN_____________\n"+studentMyContainer.min());
            System.out.println("____________INFO___________\n");
            Comparator<Student> studentComparator=new PupilComparator();
            studentMyContainer.print(studentComparator);

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
