// Submitted - 2015:02:18 03:38:51
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class TaroFillingAStringDiv2 {
	public int getNumber(String S) {
		int ans = ugly(S);

		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == '?') {
				ans = Math.min(ans, Math.min(build(S, i, 'A'), build(S, i, 'B')));
				break;
			}
		}
		return ans;
	}

	public int build(String S, int pos, char v) {
		char[] ss = S.toCharArray();

		ss[pos] = v;

		for (int i = 1; i < ss.length; i++) {
			if (ss[i] == '?') {
				if (ss[i - 1] == 'A') {
					ss[i] = 'B';
				} else {
					ss[i] = 'A';
				}
			}
		}
		return ugly(new String(ss));
	}
	public int ugly(String S) {
		int ans = 0;

		for (int i = 0; i < S.length() - 1; i++) {
			if (S.charAt(i) == '?') return Integer.MAX_VALUE;

			if (S.charAt(i) == S.charAt(i + 1)) {
				ans += 1;
			}
		}
		if (S.charAt(S.length() - 1) == '?') return Integer.MAX_VALUE;
		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
