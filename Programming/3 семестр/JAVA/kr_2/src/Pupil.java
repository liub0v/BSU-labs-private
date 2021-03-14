public class Pupil extends Learner {

    private int grade;
    private  Behavior behavior;

    public enum Behavior
    {
        SATISFACTORY, UNSATISFIED;
        private Behavior (){}
    }

    public Pupil()
    {
        super();
    }
    public Pupil(String name, String  institution, int mark,
                 int grade, Behavior behavior) throws MyException
    {
        super(name, institution, mark);
        if(grade<0 || behavior==null)
            throw new MyException("THE DATA IS INCORRECT");
        this.grade =grade;
        this.behavior=behavior;
    }
    public void print()
    {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return super.toString()+"grade "+this.getGrade()+"\n*Behavior: "+this.getBehavior()+"\n";
    }

    @Override
    public boolean equals(Object obj) {
        Pupil obj1=(Pupil)obj;
        return super.equals(obj) && this.grade ==((Pupil) obj).grade && this.behavior.equals(((Pupil) obj).behavior);
    }

    public Behavior getBehavior() {
        return behavior;
    }

    public void setBehavior(Behavior behavior) {
        this.behavior = behavior;
    }

    public Integer getGrade() {
        return grade;
    }
    public void setGrade(Integer grade) {
        this.grade = grade;
    }
}
