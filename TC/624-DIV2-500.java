// Submitted - 2014:06:14 02:25:07
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class BuildingHeightsEasy {
    public int minimum(int M, int[] heights) {
        int ans = Integer.MAX_VALUE;
        int N = heights.length;

        Arrays.sort(heights);

        for (int i = 1; i <= 50; i++) {
            int curr = 0, floor = 0;
            for (int j = 0; j < N; j++) {
                if (heights[j] == i) {
                    curr += 1;
                }
            }
            if (curr >= M) {
                ans = 0;
            } else {
                int pos = -1;
                for (int j = N - 1; j >= 0; j--) {
                    if (heights[j] < i) {
                        pos = j;
                        break;
                    }
                }
                while (pos >= 0 && curr < M) {
                    floor += (i - heights[pos]);
                    curr += 1;
                    pos -= 1;
                }
                if (curr == M) {
                    ans = Math.min(ans, floor);
                }
            }
        }

        return ans;
    }
    public void debug(Object ... obj) {
        Arrays.deepToString(obj);
    }
}

//Powered by [KawigiEdit] 2.0!
