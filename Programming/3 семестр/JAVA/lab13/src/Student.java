public class Student {
    private String  number;
    private String name;
    private String subject;
    private String mark;
    private String student;

    public Student() {
        this.name = "";
        this.subject="";
        this.number ="";
        this.mark="";
    }

    public Student(String number,String name, String subject, String mark) {
        this.name = name;
        this.number = number;
        this.subject=subject;
        this.mark=mark;

    }

    public Student(Student o) {
        this.name = o.name;
        this.number = o.number;
        this.mark=o.mark;
        this.subject=o.subject;
    }

    public void setStudent(String student) {
        this.student = student;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setMark(String mark) {
        this.mark = mark;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public String getMark() {
        return mark;
    }

    public String getNumber() {
        return number;
    }

    public String getSubject() {
        return subject;
    }

    @Override
    public String toString() {
        return "["+number + "] " + name + " " + subject +" " +mark;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return name.equals(student.name) &&
                number.equals(student.number) &&
                subject.equals(student.subject) &&
                mark.equals(student.mark);
    }
}