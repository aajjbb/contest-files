// Submitted - 2014:04:21 20:15:13
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class SlimeXSlimonadeTycoon {
	public int sell(int[] morning, int[] customers, int stale_limit) {
		int N = morning.length;
		int ans = 0, sum;

		int[] prod = new int[N];

		for (int i = 0; i < N; i++) {
			sum = 0;
			prod[i] = morning[i];

			for (int j = Math.max(0, i - stale_limit + 1); j <= i; j++) {
				sum += prod[j];

				if (sum > customers[i]) {
					sum -= prod[j];
					prod[j] -= customers[i] - sum;
					sum = customers[i];
					break;
				} else {
					prod[j] = 0;
				}
			}
			ans += sum;
		}

		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!