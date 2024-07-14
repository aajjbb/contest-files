// Submitted 2012-01-12T19:57:19-02:00

import java.util.*;

public class TwoTrains {
    public int passengerNewVasyuki(int t1, int t2, int[] times) {
        int novo = 0;
        for(int i = 0; i < times.length; i++) {
            int n = 0, o = 0;
            while(n < times[i]) n += t1;
            while(o < times[i]) o += t2;
            if(n <= o) novo++;
        }
        return novo;
    }
}

// Powered by FileEdit
