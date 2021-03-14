public abstract class Learner implements Comparable<Learner> {
    private String name;
    private String  institution;
    private int mark;

    public Learner() {
        name = "";
        institution = "";
        mark=0;
    }

    public Learner(String name, String  institution, int mark) throws MyException {
        if (name == null ||  institution==null || mark <4)
            throw new MyException("THE DATA IS INCORRECT");
        this.name= name;
        this.institution = institution;
        this.mark = mark;
    }

    public String getInstitution() {
        return institution;
    }

    public String getName() {
        return name;
    }

    public int getMark() {
        return mark;
    }

    public void setInstitution(String institution) {
        this.institution = institution;
    }

    public void setMark(int mark) {
        this.mark = mark;
    }

    public void setName(String name) {
        this.name = name;
    }

    public abstract void print();
    @Override
    public String toString() {
        return new String("[" + this.getClass().getName() + "] "
                + this.getName() + ": \n*"
                + this.getInstitution()+ ", mark "
                + this.getMark())+", ";
    }

    @Override
    public int compareTo(Learner o) {
        if (this.getMark()==o.getMark())
            return o.getName().compareTo(this.getName());
        return this.getMark()-o.getMark();
    }

    @Override
    public boolean equals(Object obj) {
        Learner obj1 = (Learner) obj;
        return this.name.equals(obj1.name) &&
                this.institution.equals(obj1.institution) &&
                this.mark==obj1.mark;
    }
}


