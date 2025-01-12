import java.util.Scanner;
public class EmployeeReport {
    float average;
    float highest;
    String highestname;
    public EmployeeReport(){
        Employee[] all = TakeInput();
        ComputeStats(all);
    }
    public Employee[] TakeInput(){
        //make scanner
        Scanner scanner = new Scanner(System.in);
        //first questi
        System.out.println("Enter the number of employees: ");
        int num = scanner.nextInt();
        Employee[] array = new Employee[num];
        for(int i=0; i < num; i++){
            System.out.println("Enter the data for employee # " + (i+1));
            array[i] = Employee.readInput();
        }
        return array;
    }
    public void ComputeStats(Employee[] a){
        int len = a.length;
        float sum = 0;
        // run through all employees adding their salaries
        for(int i=0; i < len; i++){
            float salary = a[i].getSalary();
            String name = a[i].getName();
            sum += salary;
            if(salary > highest){
                highest = salary;
                highestname = name;
            }
        }
        //calculate average
        average = sum / len;
    }
    public void DisplayResults(Employee [] a){
        System.out.println("Average salary per employee is $" + average);
        System.out.println("The highest salary is $" + highest);

    }

}
