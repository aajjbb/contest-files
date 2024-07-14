// Submitted - 2015-05-13 05:58:12
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class FoldingPaper2 {
	public int solve(int W, int H, int A) {
		int ans = -1;

		for (int i = 1; i <= A; i++) {
			if (A % i == 0) {
				int j = A / i;

				int curr = Math.min(func(W, H, i, j), func(W, H, j, i));

				if (curr == Integer.MAX_VALUE) continue;

				if (ans == -1 || curr < ans) {
					ans = curr;
				}
			}
		}

		return ans;
	}

	public int func(int W, int H, int i, int j) {
		int ans = 0;

		if (i > W || j > H) return Integer.MAX_VALUE;

		while (W > i) {
			ans += 1;
			W = (W + 1) / 2;
		}
		while (H > j) {
			ans += 1;
			H = (H + 1) / 2;
		}

		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
