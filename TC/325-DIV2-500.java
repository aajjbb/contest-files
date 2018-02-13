import java.util.*;

public class RGBStreet {
    public int estimateCost(String[] houses) {
        int n = houses.length;
        int[][] dp = new int[30][5];
        for(int i = 0; i < n; i++) {
            String[] helper = houses[i].split("\\s");
            if(i == 0) {
                dp[i][0] = Integer.parseInt(helper[0]);
                dp[i][1] = Integer.parseInt(helper[1]);
                dp[i][2] = Integer.parseInt(helper[2]);
            } else {
                dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + Integer.parseInt(helper[0]);
                dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + Integer.parseInt(helper[1]);				
                dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + Integer.parseInt(helper[2]);
            }
        }
        return Math.min(dp[n-1][0], Math.min(dp[n-1][1], dp[n-1][2]));
    }
}


// Powered by FileEdit
