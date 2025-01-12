import java.util.Scanner;

public class Employee {
    private String name;
    private float salary;

    // Default Constructor
    public Employee(){
        this.name = "newemployee";
        this.salary = 0;
    }

    // Fed Constructor
    public Employee(String name, float salary){
        this.name = name;
        this.salary = salary;
    }

    // set method for both
    public void setInfo(String name, float salary){
        this.name = name;
        this.salary = salary;
    }

    // input reader
    public static Employee readInput(){
        // make scanner
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the name of the employee: ");
        String newname = scanner.nextLine();
        System.out.println("Enter the employee's salary: ");
        float newsalary = scanner.nextFloat();
        return new Employee(newname, newsalary);
    }

    // getname
    public String getName(){
        return name;
    }

    // getsalary
    public float getSalary(){
        return salary;
    }

    //output
    public void writeOutput(){
        System.out.println("Name: "+ getName());
        System.out.println("Salary: "+ getSalary());
    }
}
