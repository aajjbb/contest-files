// Submitted 2018-11-20T00:15:20+01:00

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class MultiprocessorProgramming {
    public long optimalNumberOfProcessors(int t0, int tp, int ts) {
        long ans = 1;
        double time = t0 + tp;

        for (int i = 2; i <= (int) Math.sqrt(tp/ts) + 2; i++) {
            double currTime = Math.max(t0, tp / (double) (i - 1) + ts * (i - 1));

            if (currTime < time) {
                time = currTime;
                ans = i;
            }
        }
        return ans;
    }
}

//Powered by KawigiEdit-pf 2.3.0!
