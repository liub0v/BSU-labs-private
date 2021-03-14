import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        ArrayList<Real> numbers = new ArrayList<>();
        try {
            Scanner sc = new Scanner(new File("src/input.txt"));
            while (sc.hasNext()) {
                numbers.add(new Real(sc.nextDouble()));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println(numbers);

        Real minPositive = new Real(Double.POSITIVE_INFINITY);
        Real maxPositive = numbers.get(0);
        Real maxNegative = new Real(Double.NEGATIVE_INFINITY);

        for (Real number: numbers) {
            double doubleNumber = number.toDouble();
            double doubleMinPositive = minPositive.toDouble();
            double doubleMaxPositive = Math.abs(maxPositive.toDouble());
            double doubleMaxNegative = maxNegative.toDouble();
            if (Math.abs(doubleNumber) > doubleMaxPositive) maxPositive = number;
            if (doubleNumber > 0 && doubleNumber < doubleMinPositive) minPositive = number;
            if (doubleNumber < 0 && doubleNumber > doubleMaxNegative) maxNegative = number;
        }

        System.out.println("\nЧисло с наибольшим модулем");
        System.out.println(maxPositive);
        if (Double.compare(minPositive.toDouble(), Double.POSITIVE_INFINITY) == 0) {
            System.out.println("\nПололжительных чисел нет");
        } else {
            System.out.println("\nМинимальное положительное число");
            System.out.println(minPositive);
        }
        if (Double.compare(maxNegative.toDouble(), Double.NEGATIVE_INFINITY) == 0) {
            System.out.println("\nОтрицательных чисел нет");
        } else {
            System.out.println("\nМаксимальное отрицательное число");
            System.out.println(maxNegative);
        }
    }
}
