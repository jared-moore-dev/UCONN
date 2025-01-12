import java.util.Scanner;

public class ArrayofTemperatures {
    public static void main(String[] args) {
        // take input
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        System.out.println("How many temperature do you have? ");
        int num = scanner.nextInt();
        System.out.println("Enter " + num + " temperatures:");
        // make array
        int a[] = new int[num];
        int sum = 0;
        // Collect numbers
        for(int i = 0; i < num; i++){
            int temp = scanner.nextInt();
            a[i]=temp;
            sum += temp;
        }
        // Calculate
        float average = sum / num;
        // Printout
        System.out.println("The average temperature is " + average);
        System.out.println("Relative to the average, the temperatures are:");
        for (int j = 0; j < a.length; j++){
            float n = a[j];
            if (n > average){
                System.out.println(n + " (above average)");
            } else if (n == average){
                System.out.println(n + " (the average)");
            } else if (n < average){
                System.out.println(n + " (below average)");
            }
        }
    }
}
