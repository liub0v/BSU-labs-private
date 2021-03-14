public class Number implements Comparable<Number> {

    private int number;

    public Number (int number)
    {
        this.number=number;
    }

    @Override
    public int compareTo(Number o) {
        return this.number-o.number;
    }
    Tree<Number> numberTree=new Tree<>();
}
