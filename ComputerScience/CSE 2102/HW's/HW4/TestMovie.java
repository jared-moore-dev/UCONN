import java.util.Scanner;
public class TestMovie {
    public static void main(String[] args){
        // take input
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter the name of the movie:");
        String moviename = scanner.nextLine();
        System.out.println("Enter the MIPAA rating of the movie:"); // (1 to 5, -1 to exit:");
        String mipaa = scanner.nextLine();
        Movie m1 = new Movie(moviename, mipaa);
        while(true){
            System.out.println("Enter the rating of the movie (1 to 5, -1 to exit:");
            int rating = scanner.nextInt();
            if(rating == -1) break;
            m1.addRating(rating);
        }
        System.out.println("Name of the movie: "+ moviename);
        System.out.println("MIPAA Rating: "+ mipaa);
        System.out.println("Average Rating: "+ m1.getAverage());
    }
}
