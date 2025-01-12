
public class TemperatureConverter {
    public static void main(String[] args){
        double tempF = Double.parseDouble(args[0]);
        // The one in the homework example had bad parenthesis, a correct version of this would look like
        double tempC = (((tempF - 32)*5)/9);
        System.out.println("The Temperature in Celsius is: " + tempC);
    }
}
