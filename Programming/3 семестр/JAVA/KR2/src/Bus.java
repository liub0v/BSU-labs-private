import java.util.Comparator;

public class Bus extends Auto  {
    private int seats;
    private int doors;

    public Bus()
    {
        super();
    }
    public Bus(String name,String color,Fuel fuel,
               int seats,int doors) throws MyException
    {
        super(name,color,fuel);
        if(seats<0 || doors<0)
            throw new MyException("THE DATA IS INCORRECT");
        this.doors=doors;
        this.seats=seats;
    }

    @Override
    public void print() {
        System.out.println(this);
    }

    @Override
    public boolean equals(Object obj) {
        Bus obj1=(Bus) obj;
        return super.equals(obj) && this.seats==obj1.seats && this.doors==obj1.doors;
    }

    @Override
    public String toString() {
        return super.toString()+"\n*seats:"+seats+"\n*doots:"+doors;
    }

    public int getDoors() {
        return doors;
    }

    public int getSeats() {
        return seats;
    }

    public void setDoors(int doors) {
        this.doors = doors;
    }
    public void setSeats(int seats) {
        this.seats = seats;
    }



}
