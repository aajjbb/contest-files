// 2012-01-14T02:15:14+01:00

import java.util.*;

public class NotationLength {
    public double avgRatio(int radix, int low, int high) {
        double ave = 0.0;
        int l = 0;
        for(int i = low; i <= high; i++) {
            String a = i+"";
            String b = Integer.toString(i, radix);
            ave += (double) b.length() / a.length();
            l++;
        }
        return (double) ave / l;
    }
}


// Powered by FileEdit
