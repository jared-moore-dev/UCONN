
public class OperationsTwoNumbers {
    public static void main(String[] args){
        // Load the values from the command line
        double n1 = Double.parseDouble(args[0]);
        double n2 = Double.parseDouble(args[1]);
        // perform your calculations
        double sum = n1 + n2;
        double diff = n1 - n2;
        double prod = n1 * n2;
        double quot = n1 / n2;
        double expo = Math.pow(n1, n2);
        // Print Statements
        System.out.println("The sum of the two numbers is:\t" + sum);
        System.out.println("The difference of the two numbers is:\t" + diff);
        System.out.println("The product of the two numbers is:\t" + prod);
        System.out.println("The quotient of the two numbers is:\t" + quot);
        System.out.println("The exponentiation of the two numbers is:\t" + expo);
    }
}
