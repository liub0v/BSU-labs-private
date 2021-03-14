public final class Person implements Comparable<Person>{
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        String result = Integer.toString(this.age);
        return result;
    }

    public int compareTo(Person o) {
        return this.age - o.age;
    }

}