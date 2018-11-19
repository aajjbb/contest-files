// Submitted 11-07-2011 17:34:50

import java.util.*;

public class ApplePie {
    public int getApples(int[] x, int[] y, int[] day, int howMany) {
        int apples = 0;

        for(int i = 0; i < y.length; i++) {
            if(x[i] >= 0 && x[i] <= 100 && y[i] >= 0 && y[i] <= 100) {
                apples++;
            }
            if(apples >= howMany) return day[i];
        }
        return -1;
    }
}


// Powered by FileEdit
