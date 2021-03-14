import java.util.*;

public class MyContainer<T extends Learner> extends ArrayList<T> {

    public MyContainer()
    {
        super();
    }
    public MyContainer min() throws MyException
    {
        MyContainer<T> temp=(MyContainer)this.clone();
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        Collections.sort(temp);
        MyContainer<T> min=new MyContainer<T>();
        min.add(0,temp.get(0));
        min.add(1,temp.get(1));
        return min;

    }
   public void print(Comparator<T> Comparator) throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        MyContainer<T> temp=(MyContainer)this.clone();
        Collections.sort(temp,Comparator);
        for( var i: temp) {
            i.print();
            System.out.println();
        }
    }
    public int count(T t) throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
        return Collections.frequency(this,t);
    }
    public Double average(String institution)throws MyException
    {
        if(this.isEmpty())
            throw new MyException("CONTAINER IS EMPTY");
         return this.stream().filter(Learner->Learner.getInstitution().equals(institution)).mapToInt(Learner::getMark).average().getAsDouble();

    }

}
