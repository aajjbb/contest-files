// Submitted 2013-12-14 20:13:03

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class TheShuttles {
	public int getLeastCost(int[] cnt, int baseCost, int seatCost) {
		int x;
		int i;

		int N = cnt.length;

		int best = Integer.MAX_VALUE;

		for (x = 1; x <= maxValue(cnt); x++) {
			int curr_cost = 0;

			for (i = 0; i < N; i++) {
				int buff = 0, tp = cnt[i];

				for ( ; tp > 0; tp -= x) {
					buff += 1;
				}
				curr_cost += seatCost * (buff * x) + buff * baseCost;
			}

			System.out.println(curr_cost + " " + x);

			best = min(best, curr_cost);
		}

		return best;
	}

	public int maxValue(int x[]) {
		int ans = 0;

		for (int i: x) {
			ans = max(ans, i);
		}

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!