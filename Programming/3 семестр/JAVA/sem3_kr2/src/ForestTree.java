public class ForestTree extends Tree {

    private Integer amountOfWood;


    public ForestTree()
    {
        super();
    }
    public ForestTree(String name, int numderOfLeaves, Type type,
                      int amountOfWood) throws MyException
    {
        super(name, numderOfLeaves, type);
        if(amountOfWood<0)
            throw new MyException("THE DATA IS INCORRECT");
        this.amountOfWood =amountOfWood;
    }
    public void print()
    {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return super.toString()+"\n*"+this.getAmountOfWood()+" kg of wood;";
    }

    @Override
    public boolean equals(Object obj) {
        ForestTree obj1=(ForestTree)obj;
        return super.equals(obj) && this.amountOfWood ==((ForestTree) obj).amountOfWood;
    }

    public Integer getAmountOfWood() {
        return amountOfWood;
    }
    public void setAmountOfWood(Integer amountOfWood) {
        this.amountOfWood = amountOfWood;
    }
}
