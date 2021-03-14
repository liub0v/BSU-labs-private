import java.util.Comparator;

public class StudentComporator implements Comparator<Pupil>
{
   // @Override
    public int compare(Pupil t1, Pupil t2) {
         return t1.getInstitution().compareTo(t2.getInstitution());
    }
}
