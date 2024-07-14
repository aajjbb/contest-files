// 06-02-2013 03:12:59+01:00	Submit	aajjbb	250	247.01
using System;
using System.Collections;

public class TheEquation {
	public int leastSum(int X, int Y, int P) {
		int i, j, ans = 10000000;

		for (i = 1; i <= P; i++) for (j = 1; j <= P; j++) if ((i*X + j*Y) % P == 0) {
			ans = Math.Min(ans, i + j);
		}

		return ans;
	}
}

// Powered by FileEdit