// Submitted - 2014:06:14 02:15:56
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class CostOfDancing {
	public int minimum(int K, int[] danceCost) {
		int ans = 0, N = danceCost.length;
		Arrays.sort(danceCost);

		for (int i = 0; i < Math.min(N, K); i++) {
			ans += danceCost[i];
		}

		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
