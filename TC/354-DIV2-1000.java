import java.util.*;

public class UnsealTheSafe {
    public long countPasswords(int N) {
        long[][] dp = new long[35][15]; //Number of Digits -> Previous number selected;
        for(int i = 0; i < 10; i++) dp[1][i] = 1;
        for(int i = 2; i <= N; i++) {
            dp[i][0] = dp[i - 1][7];
            dp[i][1] = dp[i - 1][2] + dp[i - 1][4];
            dp[i][2] = dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5];
            dp[i][3] = dp[i - 1][2] + dp[i - 1][6];
            dp[i][4] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7];
            dp[i][5] = dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8];
            dp[i][6] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
            dp[i][7] = dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0];
            dp[i][8] = dp[i - 1][7] + dp[i - 1][5] + dp[i - 1][9];
            dp[i][9] = dp[i - 1][8] + dp[i - 1][6];
        }
        long ans = 0L;
        for(int i = 0; i <= 9; i++) ans += dp[N][i];
        return ans;
    }
}


// Powered by FileEdit
