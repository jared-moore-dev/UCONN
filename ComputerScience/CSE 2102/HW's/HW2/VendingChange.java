import java.util.*;
import java.io.*;

public class VendingChange {
    public static void main(String[] args) {
        // take input
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter the amount between 1 to 99:");
        int change = scanner.nextInt();
        int total = change;
        // perform Calculation
        int quarter = 0, dime = 0, nickle = 0, penny = 0;
        if (change > 0 && change <= 99)
            quarter = change / 25;
            change = change % 25;
            dime = change / 10;
            change = change % 10;
            nickle = change / 5;
            change = change % 5;
            penny = change;
        // Print Statements
        System.out.println(total + " cents in coins can be written as:");
        System.out.println(quarter + " quarters");
        System.out.println(dime + " dimes");
        System.out.println(nickle + " nickles and");
        System.out.println(penny + " pennies");
    }
}
