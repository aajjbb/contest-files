import java.util.*;

public class ReverseSums {
    public int getSum(int n) {
        StringBuilder build = new StringBuilder(String.valueOf(n)).reverse();
        return (n) + Integer.parseInt(build.toString());
    }
}
