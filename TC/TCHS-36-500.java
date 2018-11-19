// Submitted 03-01-2012

import java.util.*;

public class CrazySequence {
    public int nthNumber(String n) {
        long low = 0, high = 10000000000L, mid;
        long N = Long.parseLong(n);

        while(low < high) {
            mid = (low + high) >>> 1;
            if(mid * (mid + 1) / 2 >= N) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return (int) low;
    }
}

// Powered by FileEdit
