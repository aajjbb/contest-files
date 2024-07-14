// Submitted - 2014-11-28 18:57:44
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class AliceGameEasy {
	public long findMinimumValue(long x, long y) {
		long sum = x + y;

		long l = 0, h = 10000000, m;

		while (l <= h) {
			m = l + (h - l) / 2;

			long value = m * (m + 1) / 2;

			if (value == sum) {
				l = m;
				break;
			} else if (value < sum) {
				l = m + 1;
			} else {
				h = m - 1;
			}
		}

		if ((l * (l + 1) / 2) != sum) return -1L;

		long ans = 0L;

		while (x > 0) {
			x -= l;
			l--;
			ans += 1;
		}

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
