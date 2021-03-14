public class Car extends Auto{

    private seatMaterial material;

    public enum seatMaterial
    {
        LEATHER,SYNTHETICS;
        private seatMaterial(){}
    }
    public Car()
    {
        super();
    }
    public Car (String name,String color,Fuel fuel,
                seatMaterial material) throws MyException
    {
        super(name, color, fuel);
        if(material==null)
            throw new MyException("THE DATA IS INCORRECT");
        this.material=material;
    }
    public void print()
    {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return super.toString()+"\n*"+this.getMaterial();
    }

    @Override
    public boolean equals(Object obj) {
        Car obj1=(Car)obj;
        return super.equals(obj) && this.material==((Car) obj).material;
    }

    public seatMaterial getMaterial() {
        return material;
    }
    public void setMaterial(seatMaterial material) {
        this.material = material;
    }

}
