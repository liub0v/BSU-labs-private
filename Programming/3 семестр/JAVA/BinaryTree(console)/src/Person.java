
public final class Person implements Comparable<Person>{

    private String name;
    private String height;
    public Person(){}
    public Person(String name,String height)
    {
        this.name=name;
        this.height=height;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setHeight(String height) {
        this.height = height;
    }

    public String toString()
    {
        return this.name+" "+this.height+";";
    }

    public String getHeight() {
        return height;
    }

    public String getName() {
        return name;
    }

    public int compareTo(Person o) {
        return o.height.compareTo(this.height);
    }
    //Tree<Person> personTree=new Tree<>();

}
