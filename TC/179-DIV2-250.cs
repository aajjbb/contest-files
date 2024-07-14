// 06-03-2013 03:32:13+01:00	Submit	aajjbb	250	244.07
using System;
using System.Collections;

public class OnLineRank {
	public int calcRanks(int k, int[] scores) {
		int i, j, N = scores.Length, ans = 1;

		for (i = 1; i < N; i++) {
			int cnt = 0;
			for (j = i - 1; j >= 0 && cnt < k; j--, cnt++) {
				if (scores[j] > scores[i]) ans += 1;
			}
			ans += 1;
		}

		return ans;
	}
}

// Powered by FileEdit