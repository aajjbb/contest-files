// Submitted 14-07-2011 19:08:50

import java.util.*;

public class Fractile {
    public int fractile(int[] x, int p) {
        int ret = 0;
        Arrays.sort(x);
        boolean ct = false;
        for(int i = x.length - 1; i >= 0; i--) {
            int max = 0;
            for(int j = x.length - 1; j >= 0; j--) {
                if(x[i] >= x[j]) {
                    max++;
                }
            }
            int percentage = ((max * 100) / (x.length));
            if(percentage >= p) {
                ret = x[i];
            }
        }
        return ret;
    }
}


// Powered by FileEdit
