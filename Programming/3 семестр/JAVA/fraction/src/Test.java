import java.util.*;

class Test

{

    public static void main(String[] args) {

        try {

            Rational[] pl = new Rational[4];

            pl[0] = new Rational( 6,3);

            pl[1] = new Rational(5,8 );

            pl[2] = new Rational( 2,9);

            pl[3] = new Rational( 3,8);
            for(int i=0;i<pl.length;i++)
            {
                pl[i].reduce(pl[i]);
            }
            System.out.println("String test:");
            Rational[] str=new Rational[4];
            str[0]=new Rational("7/4") ;
            str[1]=new Rational("1/5") ;
            str[2]=new Rational("5/6") ;
            str[3]=new Rational("2/9") ;
            System.out.println(Arrays.asList(str));

            Rational.setSortBy(0);
            System.out.println( "Sorted by: " + Rational.getSortByValue() );
            Arrays.sort( pl );

            System.out.println(Arrays.asList(pl));

            Rational.setSortBy(1);
            Arrays.sort( pl );
            System.out.println( "Sorted by: " + Rational.getSortByValue() );

            System.out.println(Arrays.asList(pl));

            Rational f=new Rational();
            System.out.println("Sum: "+pl[0]+" + "+pl[1]+" = "+f.add(pl[0],pl[1]));
            System.out.println("Multiplication: "+pl[0]+" * "+pl[1]+" = "+f.multiply(pl[0],pl[1]));
            System.out.println("Division: ("+pl[0]+") / ("+pl[1]+") = "+f.divide(pl[0],pl[1]));
            System.out.println("Difference: "+pl[0]+" - "+pl[1]+" = "+f.subtract(pl[0],pl[1]));
            //System.out.println("Reduce fraction: "+pl[0]+"="+f.reduce(pl[0]));



            //exception test:

            //Rational n = new Rational(9,0);

        }

        catch ( Exception e ) {

            System.out.println( "Exception: " + e );

        }

    }

}