// Submitted - 2016-01-02 18:24:05
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class PalindromePrime {
	public int count(int L, int R) {
		int ans = 0;

		for (int i = L; i <= R; i++) {
			if (isPalindromic(i) && isPrime(i)) {
				ans += 1;
			}
		}

		return ans;
	}

	public boolean isPalindromic(int x) {
		String l = "" + x;
		String r = "";

		for (int i = 0; i < l.length(); i++) {
			r += l.charAt(l.length() - i - 1);
		}

		return l.equals(r);
	}

	public boolean isPrime(int x) {
		if (x <= 1) return false;
		if (x == 2 || x == 3) return true;
		if (x % 2 == 0 || x % 3 == 0) return false;

		for (int i = 3; i <= (int) Math.sqrt(x); i += 2) {
			if (x % i == 0) return false;
		}

		return true;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
