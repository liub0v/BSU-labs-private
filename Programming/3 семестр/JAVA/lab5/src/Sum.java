import java.util.*;
import java.util.Scanner;
import java.math.MathContext;
import java.util.InputMismatchException;
public class Sum {

    double x, k;

    public double sum(double x,double k) {
        double ch = -0.25 * x;
        double even = 0;
        double odd = 0;
        double e;
        e = 1 / (Math.pow(10, k));
        int i = 1;
        double ch1 = (1 / 9) * (x * x);

        while (Math.abs(ch) > e)
        {
            if (i % 2 != 0) {
                ch = (Math.pow(x, i) / ((i + 1) * (i + 1)));
                even += ch;
            }
            if (i % 2 == 0) {
                ch1 = Math.pow(x, i) / ((i + 1) * (i + 1));
                odd += ch1;
            }
            i++;
        }

        return odd - even;

    }


    public double check(double x)
    {
        double sum=0;
        for(int i=1; i<10;++i)
        {
            sum+=(Math.pow(-1,i)*Math.pow(x,i))/((i+1)*(i+1));
        }

        return sum;
    }

    public static void main(String[] args) {
        if (args.length > 2) {
            throw new IllegalArgumentException("only 2 arguments");}
        Scanner in = new Scanner(System.in);
        Sum object = new Sum();
        try
        {
            System.out.println("Введите значение х ( х принадлежит промежутку (0;1] ) ");
            double x = in.nextDouble();
            x=Double.parseDouble(args[0]);


            System.out.println("Введите значение K (K натуратьлое число большее 1) ");
            double k=in.nextDouble();
            k= Integer.parseInt(args[0]);

            double sum = object.sum(x, k);
            System.out.println("Сумма = " + sum);

            double sum_check = object.check(x);
            System.out.println("Проверка" + sum_check);
        }catch(Exception e)
        {
            System.out.println(e.getMessage());
            System.exit(1);
        }

    }
}