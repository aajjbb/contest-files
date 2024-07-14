// Submitted - 2015-05-21 14:41:29
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class FilipTheFrog {
	public int countReachableIslands(int[] positions, int L) {
		int ans = 1;
		int s = positions[0];
		int N = positions.length;

		Arrays.sort(positions);

		for (int i = 0; i < N; i++) {
			if (positions[i] == s) {
				for (int j = i - 1; j >= 0; j--) {
					if (positions[j + 1] - positions[j] > L) break;
					ans += 1;
				}
				for (int j = i + 1; j < N; j++) {
					if (positions[j] - positions[j - 1] > L) break;
					ans += 1;
				}
				break;
			}
		}

		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!