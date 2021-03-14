public class Number implements Comparable<Number> {
    private int value;

    public Number() {
        this.value = 0;
    }

    public Number(int number) {
        this.value = number;
    }

    public int getValue() {
        return value;
    }

    public String toString() {
        String result = Integer.toString(this.value);
        return result;
    }

    public int compareTo(Number o) {
        return this.value - o.value;
    }
}