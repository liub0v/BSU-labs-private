import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.function.BinaryOperator;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class MyContainer<T extends Tree> extends ArrayList<T> {

    public MyContainer()
    {
        super();
    }
    public T min() throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        return Collections.min(this);
    }
    /*public void information()
    {
        for( var i: this) {
            i.print();
            System.out.println();
        }
    }*/
    public void information_sorted(Comparator<T> Comparator) throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        MyContainer<T> temp=(MyContainer)this.clone();
        //Collections.sort(temp,Collections.reverseOrder());
        Collections.sort(temp,Comparator);
        for( var i: temp) {
            i.print();
            System.out.println();
        }
    }
    public int count(T auto) throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        return Collections.frequency(this,auto);
    }
   /* public T binarySearch(T auto) throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        MyContainer<T> temp=(MyContainer)this.clone();
        Collections.sort(temp);
        int index=Collections.binarySearch(temp,auto);
        if(index != -1)
            return temp.get(index);
        else
            return null;
    }*/
    public long sum(Tree.Type type)throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        int sum= this.stream().filter(Tree->Tree.getType()==type).map(Tree::getNumberOfLeaves).reduce(0,Integer::sum);
        return sum;


    }
}
