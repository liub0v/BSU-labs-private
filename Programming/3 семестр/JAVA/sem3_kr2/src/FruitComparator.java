import java.util.Comparator;

public class FruitComparator implements Comparator<FruitTree>
{
    @Override
    public int compare(FruitTree t1, FruitTree t2) {
        return t2.getNumberOfLeaves()-t1.getNumberOfLeaves();
    }
}
