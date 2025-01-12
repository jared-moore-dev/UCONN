import java.util.Scanner;
import java.io.*;

public class PrintOdd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter the first file:");
        String in = scanner.nextLine();
        System.out.println("Enter the second file:");
        String out = scanner.nextLine();

        // Writer Init
        PrintWriter outputStream = null;
        try{
            outputStream = new PrintWriter(out);
        } catch(FileNotFoundException e){
            System.out.println("Error opening the file" + out);
            System.exit(0);
        }
        // Reader init
        Scanner inputStream = null;
        try {
            inputStream = new Scanner(new File(in));
        } catch (FileNotFoundException e){
            System.out.println("Error opening the file "+ in);
            System.exit(0);
        }

        //Loop through each and append and write
        while(inputStream.hasNextLine()){
            String line = inputStream.nextLine();
            // do the string concatenation here
            line = line.substring(line.indexOf(" "));
            outputStream.println(line);
        }
        outputStream.close(); // close the output file
    }
}
