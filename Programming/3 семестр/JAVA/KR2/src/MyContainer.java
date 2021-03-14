import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.function.Predicate;

public class MyContainer<T extends Auto> extends ArrayList<T> {

    public MyContainer()
    {
        super();
    }
    public T max() throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        return Collections.max(this);
    }
    public void information()
    {
        for( var i: this) {
            i.print();
            System.out.println();
        }
    }
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
    public int amount(T auto) throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        return Collections.frequency(this,auto);
    }
    public T binarySearch(T auto) throws MyException
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
    }
    public long count(Auto.Fuel type)throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        return this.stream().filter(new Predicate<T>() {
            @Override
            public boolean test(T t) {
                return t.getFuel()==type;
            }
        }).count();

    }
}
