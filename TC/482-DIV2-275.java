import java.util.*;
import java.math.*;

public class AverageAverage {
    public double average(int[] numList) {
        double nums = 0.0, div = 0;
        for(int i = 0; i < (1 << numList.length); i++) {
            double check = 0.0, size = 0;
            for(int j = 0; j < numList.length; j++) if(((i>>j)&1) != 0) {
                    check += (double) numList[j];
                    size += 1;
                }
            if(size != 0) {
                nums += (double)check/size;
                div += 1;
            }
        }
        return nums / div;
    }
}


// Powered by FileEdit
