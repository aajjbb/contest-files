// Submitted - 2015-10-16 06:31:43
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class Cdgame {
	public int rescount(int[] a, int[] b) {
		Set<Integer> set = new HashSet<Integer>();
		int N = a.length;
		int M = b.length;

		int sA = 0;
		int sB = 0;

		for (int i = 0; i < N; i++) {
			sA += a[i];
		}
		for (int i = 0; i < M; i++) {
			sB += b[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sA -= a[i];
				sB -= b[j];

				set.add((sA + b[j]) * (sB + a[i]));

				sA += a[i];
				sB += b[j];
			}
		}
		return set.size();
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!