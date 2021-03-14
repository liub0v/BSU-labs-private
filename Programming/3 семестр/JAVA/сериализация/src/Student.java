//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

//import Instrument.Type;
import java.io.Serializable;

public class Student extends Learner implements Serializable {
    private static final long serialVersionUID = 1L;

    public Student(String name) {
        super(name, Type.STUDENT);
    }
    public Student() {}
}
