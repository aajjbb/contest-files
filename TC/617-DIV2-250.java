// Submitted - 2014:04:21 19:35:59
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class SilverbachConjecture {
	public int[] solve(int n) {
		for (int i = 4; ; i++) {
			if (func(i) && func(n - i)) {
				return new int[] {i, n - i};
			}
		}
	}

	public boolean func(int n) {
		if (n == 2) {
			return true;
		} else if (n == 3 || n % 2 == 0) {
			return true;
		} else {
			for (int i = 3; i < n; i += 2) {
				if (n % i == 0) {
					return true;
				}
			}
			return false;
		}
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!