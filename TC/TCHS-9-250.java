// Submitted 14-07-2011 17:03:29
import java.util.*;

public class ExcitingGame {
    public int howMany(int nClassmates, int nTimes, int who) {
        int num = 0;
        int count = 0;

        for(int i = 1; i <= nTimes; i++) {
            if(i % 3 == 0 && (i - 1) % nClassmates == who) num++;
        }
        return num;
    }
}

// Powered by FileEdit
