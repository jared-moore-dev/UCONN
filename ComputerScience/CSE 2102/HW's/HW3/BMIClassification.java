import java.util.Scanner;

public class BMIClassification {
    public static void main(String[] args) {
        // take input
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter your weight in pounds. ");
        float weight = scanner.nextFloat();
        System.out.println("Enter your height in inches. ");
        float height = scanner.nextFloat();
        float bmi = (weight * 703) / (height * height);
        System.out.println("Your BMI is " + bmi);
        if(bmi < 18.5){
            System.out.println("Your risk category is Underweight");
        } else if (bmi > 18.5 && bmi < 25) {
            System.out.println("Your risk category is Normal Weight");
        } else if (bmi > 25 && bmi < 30) {
            System.out.println("Your risk category is Overweight");
        } else if (bmi > 30) {
            System.out.println("Your risk category is Obese");
        }
    }
}