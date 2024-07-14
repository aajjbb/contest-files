// Submitted 2012-01-12T22:12:59+01:00

import java.util.*;

public class ProductSet {
    public int howMany(int[] low, int[] high) {
        Set<Integer> s = new HashSet<Integer>();

        for(int i = low[0]; i <= high[0]; i++) {
            for(int j = low[1]; j <= high[1]; j++) {
                for(int k = low[2]; k <= high[2]; k++) {
                    s.add(i * j * k);
                }
            }
        }

        return s.size();
    }
}

// Powered by FileEdit
