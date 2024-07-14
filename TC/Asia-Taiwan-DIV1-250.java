// Submitted - 2014:08:23 02:36:53
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class SquareVerification {
	public int calculateCode(int x) {
		int best = 0;
		long y = x * (long) x;

		while (y > 0) {
			best = Math.max(best, (int) y % 10);
			y /= 10;
		}
		return best;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!