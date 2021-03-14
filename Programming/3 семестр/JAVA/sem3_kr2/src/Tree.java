public abstract class Tree implements Comparable<Tree> {
    private String name;
    private Integer numberOfLeaves;
    private Type type;

    public enum Type {
        DECIDUOUS, CONIFER;
        private Type() {
        }
    }

    public Tree() {
        name = "";
        numberOfLeaves = 0;
    }

    public Tree(String name, int  numberOfLeaves, Type type) throws MyException {
        if (name == null ||  numberOfLeaves <0 || type == null)
            throw new MyException("THE DATA IS INCORRECT");
        this.name= name;
        this.numberOfLeaves = numberOfLeaves;
        this.type = type;
    }

    public int getNumberOfLeaves() {
        return numberOfLeaves;
    }

    public String getName() {
        return name;
    }

    public Type getType() {
        return type;
    }

    public void setNumberOfLeaves(int numberOfLeaves) {
        this.numberOfLeaves = numberOfLeaves;
    }

    public void setType(Type type) {
        this.type = type;
    }

    public void setName(String name) {
        this.name = name;
    }

    public abstract void print();
    @Override
    public String toString() {
        return new String("[" + this.getClass().getName() + "] "
                + this.getName() + ": \n*"
                + this.getNumberOfLeaves()+ " leaves"+ "\n*"
                + this.getType());
    }

    @Override
    public int compareTo(Tree tree) {
        if (this.getNumberOfLeaves()==tree.getNumberOfLeaves())
            return tree.getName().compareTo(this.getName());//по убыванию
        return tree.getNumberOfLeaves()-this.getNumberOfLeaves();
    }

    @Override
    public boolean equals(Object obj) {
        Tree tree = (Tree) obj;
        return this.name.equals(tree.name) &&
                this.numberOfLeaves==tree.numberOfLeaves &&
                this.type.equals(tree.type);
    }
}


