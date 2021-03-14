import java.util.Comparator;

public class CarComporator implements Comparator<Car>
{
   // @Override
    public int compare(Car t1, Car t2) {
        return t2.getName().compareTo(t1.getName());
    }
}
