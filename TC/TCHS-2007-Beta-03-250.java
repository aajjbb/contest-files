// Submitted 20-09-2011

import java.util.*;

public class CandyBoxes {
    public int remainingCandies(int[] candies) {
        int max = -1, min = 100001, N = candies.length - 1;
        Set<Integer> set = new HashSet<Integer>();
        for(int i: candies) set.add(i);
        if(N == 0 || set.size() == 1) return candies[0];
        while(true) {
            Arrays.sort(candies);
            candies[N] -= candies[0];
            Arrays.sort(candies);

            if(candies[N] == candies[0]) { return candies[0]; }
        }
    }
}

// Powered by FileEdit
