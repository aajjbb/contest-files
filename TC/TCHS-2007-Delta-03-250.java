// 2011-09-05T20:11:56+01:00

import java.util.*;

public class AdvertisingAgency {
    public int numberOfRejections(int[] requests) {
        int ret = 0;

        Set<Integer> set = new HashSet<Integer>();
        for(int i: requests) set.add(i);

        for(int i: set) {
            int pos = 1;
            for(int j: requests) {
                if(i == j) {
                    pos++;
                }
            }
            ret += pos - 2;
        }
        return ret;
    }
}


// Powered by FileEdit
