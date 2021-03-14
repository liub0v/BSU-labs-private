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

    ///////////////////////////////////////////////////
    // area names
    int a,b;
    Integer[] areas = {a,b};
    Rational(int a,int b)
    {
        //this.a=a;
        //this.b=b;
        areas[0]=a;
        areas[1]=b;
    }

    public static final String [] fraction={"a","b"};

    ///////////////////////////////////////////////////
    // sort index

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

    ///////////////////////////////////////////////////
    //  checkers (stubs)

    protected boolean validAB( Integer a,Integer b) {
        return b != 0 && a%b!=0;
    }


    /////////////////////////////////////////
    // areas container


    // indexator:
    public int length() {
        return areas.length;
    }
    public Integer getArea( int idx ) {
        if ( idx >= length() || idx < 0 ) {
            throw new IndexOutOfBoundsException();
        }
        return areas[idx];
    }
    public void setArea( int idx, Integer value ) throws ArgException {
        if ( idx >= length() || idx < 0 ) {
            throw new IndexOutOfBoundsException();
        }
        //if (( idx == 0 && validAB( value )== false )) {
           // throw new ArgException( value );
       // }
        areas[idx] = value;
    }

    //Iterable<String>, Iterator<String>
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
    //Comparable<Contact>
    public int compareTo( Rational cy ) {
        return areas[Rational.sortBy].compareTo( cy.areas[Rational.sortBy] );
    }
    // toString
    public String toString() {
        String res = areas[0]+"/"+areas[1];
        return res;
    }
    // constructors:
    //public Contact() {}
    private void setup( Integer a,Integer b ) throws ArgException {
        areas = new Integer[2];
        setArea(0,a);
        setArea(1,b);

    }





}

