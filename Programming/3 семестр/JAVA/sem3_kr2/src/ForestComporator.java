import java.util.Comparator;

public class ForestComporator implements Comparator<ForestTree>
{
   // @Override
    public int compare(ForestTree t1, ForestTree t2) {
        return t2.getNumberOfLeaves()-t1.getNumberOfLeaves();
    }
}
