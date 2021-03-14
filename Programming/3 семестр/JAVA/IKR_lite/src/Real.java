public class Real {
    private boolean negative;
    private double integer;
    private double fractional;

    Real(double value) {
        negative = value < 0;
        double absoluteValue = Math.abs(value);
        integer = (int)Math.floor(absoluteValue);
        fractional = absoluteValue - integer;
    }

    double toDouble(){
        double value = integer + fractional;
        if (negative) value *= -1;
        return value;
    }

    @Override
    public String toString() {
        return "{" + toDouble() + "}";
    }
}
