import java.util.*;

class test

{


    public static void main(String[] args) {

        try {

            Rational[] pl = new Rational[4];

            pl[0] = new Rational( 1,3);

            pl[1] = new Rational(5,9 );

            pl[2] = new Rational( 4,9);

            pl[3] = new Rational( 3,8);

        Rational.setSortBy(0);
        System.out.println( "----- Sorted by: " + Rational.getSortByValue() );
        Arrays.sort( pl );

        System.out.println(Arrays.asList(pl));

        Rational.setSortBy(1);
        Arrays.sort( pl );
        System.out.println( "----- Sorted by: " + Rational.getSortByValue() );

        System.out.println(Arrays.asList(pl));


    //exception test:

            Rational n = new Rational(9,0);

        }

        catch ( Exception e ) {

            System.out.println( "Exception: " + e );

        }

    }

}