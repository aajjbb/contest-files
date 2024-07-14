// Submitted - 2015-03-22 03:13:23
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class CountryGroup {
	public int solve(int[] a) {
		int N = a.length;
		int ans = 0;

		for (int i = 0; i < N; i++) {
			int j = i, c = 0;
			for ( ; j < N && (j - i + 1 <= a[i]); j++) {
				if (a[i] != a[j]) {
					break;
				}
				c += 1;
			}
			if (c != a[i]) {
				ans = -1;
				break;
			}
			ans += 1;
			i = j - 1;
		}
		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!