import java.util.*;

public class Rational implements
        Comparable<Rational>,
        Iterable<Integer>, Iterator<Integer>
{
    ///////////////////////////////////////////////////
    // argument exception


    public static class ArgException extends Exception {
        private static final long serialVersionUID = 1L;

        ArgException( String arg ) {
            super( "Invalid argument: " + arg );
        }
    }

    int a,b;
    Integer[] areas = {a,b};
    Rational(int a,int b)
    {
        areas[0]=a;
        areas[1]=b;
    }
    Rational(){}

    public static final String [] fraction={"a","b"};

    private static int sortBy = 0;
    public static int getSortBy() {
        return sortBy;
    }
    public static void setSortBy( int value ) {
        if ( value >= fraction.length || value < 0 ) {
            throw new IndexOutOfBoundsException();
        }
        sortBy = value;
    }
    public static String getSortByValue() {
        return Rational.fraction[Rational.getSortBy()];
    }

    protected boolean validAB( Integer a,Integer b) {
        return b != 0 && a%b!=0;
    }

    public int length() {
        return areas.length;
    }

    public Integer getArea( int idx ) {
        if ( idx >= length() || idx < 0 ) {
            throw new IndexOutOfBoundsException();
        }
        return areas[idx];
    }
    public void setArea( int idx, String value ) throws ArgException {
        if ( idx >= length() || idx < 0 ) {
            throw new IndexOutOfBoundsException();
        }

        areas[idx] = Integer.parseInt(value);

    }

    public Iterator<Integer> iterator() {
        reset();
        return this;
    }

    private int iterator_idx = 0;
    public void reset() {
        iterator_idx = 0;
    }

    public boolean hasNext() {
        return iterator_idx >= areas.length ? false: true;
    }

    public void remove() {
        //
    }

    public Integer next() {
        if ( iterator_idx < areas.length ) {
            return areas[iterator_idx++];
        }
        reset();
        return null;
    }

    public int compareTo( Rational cy ) {

        return areas[Rational.sortBy].compareTo( cy.areas[Rational.sortBy] );
    }

    public String toString() {
        String res = areas[0]+"/"+areas[1];
        return res;
    }

    private void setup( String a,String b ) throws ArgException {

        setArea(0,a);
        setArea(1,b);
        if ( getArea(0)%getArea(1)==0 ) {

            throw new ArgException( "not radial fraction introduced" );

        }
    }

    public Rational( String str ) throws ArgException {
        if ( str == null ) {

            throw new ArgException( "null pointer passed for str" );

        }

        String[] args = str.split("/");
        setArea(0, args[0]);
        setArea(1, args[1]);

    }

    public Rational add(Rational f1, Rational f2)
    {
        Rational f3=new Rational();
        f3.areas[0]=f1.areas[0]*f2.areas[1]+f2.areas[0]*f1.areas[1];
        f3.areas[1]=f1.areas[1]*f2.areas[1];
        return f3 ;
    }
    public Rational multiply(Rational f1,Rational f2)
    {
        Rational f3=new Rational();
        f3.areas[0]=f1.areas[0]*f2.areas[0];
        f3.areas[1]=f1.areas[1]*f2.areas[1];
        return f3;
    }
    public Rational divide(Rational f1, Rational f2)
    {
        Rational f3=new Rational();
        f3.areas[0]=f1.areas[0]*f2.areas[1];
        f3.areas[1]=f1.areas[1]*f2.areas[0];
        return f3;

    }
    public Rational subtract (Rational f1, Rational f2)
    {
        Rational f3=new Rational();
        f3.areas[0]=f1.areas[0]*f2.areas[1]-f2.areas[0]*f1.areas[1];
        f3.areas[1]=f1.areas[1]*f2.areas[1];
        return f3 ;
    }

    public Rational reduce(Rational f)
    {
        int a=f.areas[0];
        int b=f.areas[1];
        Rational fr=new Rational();
        if(f.areas[0]%f.areas[1]==0 || f.areas[1]%f.areas[2]==0  )
        {
            long limit = Math.min(a, b);

            for (long i = 2; i <= limit; i++) {
                if (a % i == 0 && b % i == 0) {
                    a /= i;
                    b /= i;
                }
            }
            fr.areas[0]=a;
            fr.areas[1]=b;
            return fr;
        }
        return f;
    }
}

