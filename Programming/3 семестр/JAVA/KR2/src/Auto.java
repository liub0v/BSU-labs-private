import javax.swing.*;
import java.util.Comparator;

public abstract class Auto implements Comparable<Auto> {
    private String name;
    private String color;
    private Fuel fuel;

    public enum Fuel {
        PETROL, DIESEL;

        private Fuel() {
        }
    }

    public Auto() {
        name = "";
        color = "";
    }

    public Auto(String name, String color, Fuel fuel) throws MyException {
        if (name == null || color == null || fuel == null)
            throw new MyException("THE DATA IS INCORRECT");
        this.name= name;
        this.color = color;
        this.fuel = fuel;
    }

    public String getColor() {
        return color;
    }

    public String getName() {
        return name;
    }

    public Fuel getFuel() {
        return fuel;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setFuel(Fuel fuel) {
        this.fuel = fuel;
    }

    public void setName(String name) {
        this.name = name;
    }

    public abstract void print();

    @Override
    public String toString() {
        return new String("[" + this.getClass().getName() + "] "
                + this.getName() + ": \n*"
                + this.getColor() + "\n*"
                + this.getFuel());
    }

    @Override
    public int compareTo(Auto auto) {
        if (this.getName().equals(auto.getName()))
            return auto.getFuel().compareTo(this.getFuel());//по убыванию
        return this.getName().compareTo(auto.getName());//по возрастанию

    }

    @Override
    public boolean equals(Object obj) {
        Auto auto = (Auto) obj;
        return this.name.equals(auto.name) &&
                this.color.equals(auto.color) &&
                this.fuel.equals(auto.fuel);
    }
}


