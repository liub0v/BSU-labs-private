import java.util.Comparator;

public class BusComparator  implements Comparator<Bus>
{
    @Override
    public int compare(Bus t1, Bus t2) {
        return t1.getName().compareTo(t2.getName());
    }
}
