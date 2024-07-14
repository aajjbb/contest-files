// 02-03-2015 01:26:54+01:00	Submit	aajjbb	900	576.80
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class LoadBalancing {
	public int minTime(int[] chunkSizes) {
		int N = chunkSizes.length;

		if (N == 0) return 0;

		int sum = 0;
		int bst = Integer.MAX_VALUE;

		for (int i = 0; i < N; i++) {
			chunkSizes[i] /= 1024;
			sum += chunkSizes[i];
		}


		boolean[] dp = new boolean[204810];

		dp[0] = true;

		for (int i = 0; i < N; i++) {
			for (int j = sum; j >= chunkSizes[i]; j--) {
				dp[j] |= dp[j - chunkSizes[i]];

				if (dp[j]) {
					bst = Math.min(bst, Math.max(j, sum - j));
				}
			}
		}

		return bst * 1024;
	}
	public void debug(Object ... obj) {
		System.out.println(Arrays.deepToString(obj));
	}
}

//Powered by [KawigiEdit] 2.0!
