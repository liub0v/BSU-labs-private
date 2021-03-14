public class Main {

    public static void main(String[] args) throws InterruptedException{
        BinaryTree <Integer> t = new BinaryTree<>();

        Person[] persons = {new Person("Alice", 50), new Person("Antony", 25),
                new Person("Bob", 75), new Person("Mark", 12),
                new Person("Mary", 37), new Person("Ron", 73),
                new Person("Sam", 87), new Person("Robin", 22)};
        BinaryTree<Person> personTree = new BinaryTree<>();
        for (Person person : persons) {
            personTree.insert(person);
        }

        Number[] numbers = {new Number(50), new Number(25), new Number(75),
                new Number(12), new Number(37), new Number(43), new Number(30),
                new Number(33), new Number(18), new Number(54), new Number(82),
                new Number(67), new Number(56), new Number(79)};

        BinaryTree<Number> numberTree = new BinaryTree<>();
        for (Number number : numbers) {
            numberTree.insert(number);
        }

        TreeGUI treeGUI = new TreeGUI(numberTree);
    }
}