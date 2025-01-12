import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TransactionReport {
    public static void main(String[] args) {
        // take input
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Please enter the transaction filename: ");
        String filename = scanner.next();
        // try to open file
        Scanner inputStream = null;
        try{
            inputStream = new Scanner(new File(filename));
        } catch (FileNotFoundException e) {
            System.out.println("Error openning the file "+filename+". Check to ensure its there and try again");
            System.exit(0);
        }
        System.out.println("File Opened");
        // Retrieve data
        float sum = 0;
        inputStream.nextLine(); // skip the first line
        // String a[] = new String[4];
        while (inputStream.hasNextLine()){
            String line = inputStream.nextLine();
            //a = line.split(",");
            ArrayList<String> mylist = new ArrayList<String>(Arrays.asList(line.split(",")));
            String sku = mylist.get(0);
            String qt = mylist.get(1);
            String price = mylist.get(2);
            String desc = mylist.get(3);
            float numprice = Float.parseFloat(price);
            float numqt =  Float.parseFloat(qt);
            float total = numprice * numqt;
            sum += total;
            System.out.println("Sold "+qt+" of "+desc+" (SKU: "+sku+") at $"+price+" each. Sale is $"+total);
        }
        System.out.println("Total sales: $"+sum);

    }
}
