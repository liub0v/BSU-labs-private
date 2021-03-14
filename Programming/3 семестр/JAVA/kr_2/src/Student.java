public class Student extends Learner {
    private int course;

    public Student()
    {
        super();
    }
    public Student(String name, String institution, int mark,
                   int course) throws MyException
    {
        super(name, institution,mark);
        if(course<0)
            throw new MyException("THE DATA IS INCORRECT");
        this.course =course;
    }

    @Override
    public void print() {
        System.out.println(this);
    }
    @Override
    public boolean equals(Object obj) {
        Student obj1=(Student) obj;
        return super.equals(obj) && this.course ==obj1.course;
    }

    @Override
    public String toString() {
        return super.toString()+ course +" course\n";
    }

    public int getCourse() {
        return course;
    }
    public void setCourse(int course) {
        this.course = course;
    }



}
