// 2012-01-05T23:46:14+01:00
import java.util.*;

public class CommutePlan {
    public int shortestRoute(int distance, int[] cutS, int[] cutE, int[] cutL) {
        int[] dp = new int[1064];
        int N = cutS.length;

        for(int i = 1; i <= distance; i++) {
            dp[i] = dp[i - 1] + 1;
            for(int j = 0; j < N; j++) {
                if(cutE[j] == i) {
                    if(dp[i] > dp[cutS[j]] + cutL[j]) {
                        dp[i] = dp[cutS[j]] + cutL[j];
                    }
                }
            }
        }
        return dp[distance];
    }
}
