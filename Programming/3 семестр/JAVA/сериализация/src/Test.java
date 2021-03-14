//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

import java.util.ArrayList;

public class Test {
    public Test() {}

    public static Learner[] createBand() {
        Learner[] learners = new Learner[4];
        learners[0] = new Student("Kurets Liubou");
        learners[0].setInfo("2 course");
        learners[1] = new Schoolchild("Golovskaya Katherine");
        learners[1].setInfo("grade 11");
        learners[2] = new Schoolchild("Suhinin Konstantin");
        learners[2].setInfo("grade 3");
        learners[3] = new Student("Shybut Eliz");
        learners[3].setInfo("2 course");
        return learners;
    }


    public static void main(String[] args) {
        try {
            Connector con = new Connector("learners.dat");
            con.write(createBand());
            Learner[] learners = con.read();

            ArrayList<Learner> arr1$=new ArrayList<Learner>();
            ArrayList<Learner> arr2$=new ArrayList<Learner>();

            for(Learner i:learners){
                if(i.getType()== Learner.Type.SCHOOLCHILD)
                    arr1$.add(i);
                else
                    arr2$.add(i);
            }

            System.out.println("The learners: ");
            System.out.println("   *Students:");
            arr2$.forEach(System.out::println);
            System.out.println("   *Pupils:");
            arr1$.forEach(System.out::println);

        } catch (Exception var7) {
            System.err.println(var7);
        }

    }
}
