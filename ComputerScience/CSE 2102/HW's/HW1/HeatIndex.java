public class HeatIndex {
    public static void main(String[] args){
        // Commandline Parse input
        double T = Double.parseDouble(args[0]);
        double R = Double.parseDouble(args[1]);
        // Static Variable Loading
        double c1 = - 8.78469475556;
        double c2 = 1.61139411;
        double c3 = 2.33854883889;
        double c4 = -0.14611605;
        double c5 = -0.012308094;
        double c6 = -0.0164248277778;
        double c7 = 0.002211732;
        double c8 = 0.00072546;
        double c9 = -0.000003582;
        // Calculation
        double HI = c1 + (c2 * T) + (c3 + R) + (c4*T*R) + (c5*T*T) + (c6*R*R) + (c7*T*T*R) + (c8*T*R*R) + (c9*T*T*R*R);
        // Print Statement for Temp, Humidity, and Heat index
        System.out.println("Temperature:\t" + T + " degree celsius");
        System.out.println("Relative Humidity:\t" + R);
        System.out.println("Heat Index:\t" + HI);
    }
}
