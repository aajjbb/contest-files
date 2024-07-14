// 2011-08-01T14:27:40+01:00
import java.util.*;

public class ReverseSums {
    public int getSum(int n) {
        StringBuilder build = new StringBuilder(String.valueOf(n)).reverse();
        return (n) + Integer.parseInt(build.toString());
    }
}
