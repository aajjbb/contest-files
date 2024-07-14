// 2011-12-26T16:50:15+01:00

import java.util.*;

public class DogAndRabbit {
    public String willCatch(int distr, int disth, int rSpeed, int dogAcc) {
        String ans = "";
        if(distr == 0) return "YES";
        if(dogAcc == 0) return "NO";

        long tdog = (long) dogAcc * disth * disth;
        long rabbit = (long) 2 * rSpeed * rSpeed * (disth + distr);

        if(tdog >= rabbit) {
            ans = "YES";
        } else {
            ans = "NO";
        }

        return ans;
    }
}

// Powered by FileEdit
