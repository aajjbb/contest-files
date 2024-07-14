// 2011-07-27T23:04:01-02:00

import java.util.*;

public class TriangleConstruction {
    public int greatestPerimeter(int[] l) {
        int max = 0;
        Arrays.sort(l);

        for(int N = l.length - 1; N >= 2; N--) {
            if(l[N - 2] + l[N - 1] > l[N]) {
                max = Math.max(max, (l[N] + l[N - 1] + l[N - 2]));
            }
        }
        if(max == 0) {
            return -1;
        } else {
            return max;
        }
    }
}

// Powered by FileEdit
