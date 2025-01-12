import java.util.Locale;
import java.util.Scanner;

public class StringConcat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        // Take inputs
        System.out.println("Enter the first string:");
        String first = scanner.nextLine();
        System.out.println("Enter the second string:");
        String second = scanner.nextLine();

        // .ToLowerCase them both
        String Lfirst = first.toLowerCase();
        String Lsecond = second.toLowerCase();
        // Concat them
        String s = Lfirst + Lsecond;
        // Print Statements
        System.out.println("The concatenated string is: " + s);
        int i = s.length();
        System.out.println("The length of the concatenated string is: " + i);
    }
}