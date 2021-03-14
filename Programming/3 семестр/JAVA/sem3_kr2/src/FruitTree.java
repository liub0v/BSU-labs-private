public class FruitTree extends Tree  {
    private int cropWeight;

    public FruitTree()
    {
        super();
    }
    public FruitTree(String name, int  numberOfLeaves, Type type,
                     int cropWeight) throws MyException
    {
        super(name, numberOfLeaves,type);
        if(cropWeight<0)
            throw new MyException("THE DATA IS INCORRECT");
        this.cropWeight =cropWeight;
    }

    @Override
    public void print() {
        System.out.println(this);
    }
    @Override
    public boolean equals(Object obj) {
        FruitTree obj1=(FruitTree) obj;
        return super.equals(obj) && this.cropWeight ==obj1.cropWeight;
    }

    @Override
    public String toString() {
        return super.toString()+"\n*"+ cropWeight+" kg of crop;";
    }

    public int getCropWeight() {
        return cropWeight;
    }
    public void setCropWeight(int cropWeight) {
        this.cropWeight = cropWeight;
    }



}
