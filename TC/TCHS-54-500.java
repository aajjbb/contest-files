// 06-07-2012 02:18:44
import java.util.*;
import java.math.*;

public class SegmentDisplay {
	public int howManyNumbers(int n) {
		int[] dp = new int[500010];
		int[] digits = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
		int MOD = 1000000007;
		
		if(n == 0) return 0;
		
		dp[0] = 1;
		
		for(int i = 0; i <= n + 1; i++) {
			for(int j = 0; j < 10; j++) {
				if(i >= digits[j] && (i != n || j != 0)) {
					dp[i] = (dp[i] + dp[i - digits[j]]) % MOD;
				}
			}
		}
		return dp[n] + (n == 6 ? 1 : 0) % MOD;
	}	
}


// Powered by FileEdit
