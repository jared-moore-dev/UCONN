public class main {
    public static void main(String[] args){
        EmployeeReport r = new EmployeeReport();
        Employee[] all = r.TakeInput();
        r.ComputeStats(all);
        r.DisplayResults(all);
    }
}
