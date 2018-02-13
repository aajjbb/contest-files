import java.util.*;
import java.math.*;

public class CircularLine {
    public int longestTravel(int[] t) {
        int ans = 0, n = t.length;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) if(i != j) {
                    ans = Math.max(ans, minimal(i, j, t));
                }
        }
        return ans;
    }
    public int minimal(int f, int t, int[] time) {
        int cost_forward = 0, cost_backward = 0;
        int start = f;
        while(start != t) {
            cost_forward += time[start];
            start += 1;
            if(start == time.length) start = 0;
        }
        start = f;
        while(start != t) {
            if(start == 0) start = time.length;
            cost_backward += time[start - 1];
            start -= 1;
        }
        return Math.min(cost_forward, cost_backward);
    }
}


// Powered by FileEdit
