// Submitted 11-07-2011 16:55:01

import java.util.*;

public class SpeedRadar {
    public double averageSpeed(int minLimit, int maxLimit, int[] readings) {
        double divisor = 0;
        int falty = 0;
        for(int i = 0; i < readings.length; i++) {
            if(readings[i] > maxLimit || readings[i] < minLimit) {
                falty++;
            } else {
                divisor += readings[i];
            }
        }
        if(falty * 10 > readings.length) return 0.0;
        return (divisor / (readings.length - falty));
    }
}


// Powered by FileEdit
