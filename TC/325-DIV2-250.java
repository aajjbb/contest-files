import java.util.*;

public class SalaryCalculator {
    public double calcHours(int P1, int P2, int salary) {
        if(P1 * 200 >= salary) {
            return (double) salary / P1;
        } else {
            return (double) (salary - P1 * 200) / P2 + 200;
        }
    }
}

// Powered by FileEdit
