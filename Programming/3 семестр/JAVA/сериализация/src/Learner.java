//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

import java.io.Serializable;

public class Learner implements Serializable {
    private String name;
    private Learner.Type type;
    private String info = "";


    public String getName() {
        return this.name;
    }

    public Learner.Type getType() {
        return this.type;
    }

    public String getInfo() {
        return this.info;
    }

    public void setInfo(String info) {
        this.info = info;
    }

    public String toString() {
        return new String("Leaner: " + this.name + " type: " + this.type.toString() + " info: " + this.info);
    }

    public Learner() {}

    protected Learner(String name, Learner.Type type) {
        this.name = name;
        this.type = type;
    }

    public static enum Type {
        STUDENT,
        SCHOOLCHILD;
        private Type() {}
    }
}
