import java.util.Comparator;

public class PupilComparator implements Comparator<Student>
{
    @Override
    public int compare(Student t1, Student t2) {
        return t1.getInstitution().compareTo(t2.getInstitution());
    }
}
