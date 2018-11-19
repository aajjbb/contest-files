// 14-07-2011 09:22:40

import java.util.*;

public class FussySleeper {
    public int[] nextTime(int[] currentTime, int elephants) {
        int[] time = {currentTime[0], currentTime[1]};
        do {
            time[1]++;
            if(time[1] >= 60) {
                time[0]++;
                time[1] = 0;
            } if(time[0] > 23) {
                time[0] = 0;
            }
        } while(((time[0] * 100) + time[1]) % elephants != 0);
        return time;
    }
}

// Powered by FileEdit
