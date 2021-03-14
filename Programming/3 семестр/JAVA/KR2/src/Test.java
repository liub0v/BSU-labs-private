import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.net.SocketTimeoutException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner scanner1=null;
        Scanner scanner2=null;
        try {
            MyContainer<Car> car = new MyContainer<>();
            MyContainer<Bus> bus = new MyContainer<>();
            scanner1 = new Scanner(new File("input1.txt"));
            while (scanner1.hasNext())
                car.add(new Car(scanner1.next(), scanner1.next(), Car.Fuel.valueOf(scanner1.next().toUpperCase()), Car.seatMaterial.valueOf(scanner1.next())));
            scanner2 = new Scanner(new File("input2.txt"));
            while (scanner2.hasNext())
                bus.add(new Bus(scanner2.next(),scanner2.next(),Bus.Fuel.valueOf(scanner2.next()),scanner2.nextInt(),scanner2.nextInt()));
            System.out.println("Count_Diesel: "+car.count(Auto.Fuel.DIESEL));
            System.out.println("Count_Petrol: "+car.count(Auto.Fuel.PETROL));
            System.out.println("Amount: "+ car.amount(car.get(0)));
            System.out.println("MAX:\n "+car.max());
            System.out.println("Search:\n "+car.binarySearch(car.get(2))+"\n");
            car.sort(null);
            car.information();
            System.out.println("Сортировка по убыванию");
            Comparator<Car> car_Comparator=new CarComporator();
            car.information_sorted(car_Comparator);
            //bus.information();
        }catch (FileNotFoundException e) {
            System.out.println(e);
        }catch (InputMismatchException e) {
            System.out.println("INCORRECT ENTRY");
        }catch (MyException e) {
            System.out.println(e.getMessage());
            return;
        }finally {
            if(scanner1!=null)
                scanner1.close();
            if(scanner2!=null)
                scanner2.close();
        }

    }

}
