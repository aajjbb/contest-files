// 08-30-2015 17:45:11+01:00	Submit	aajjbb	500	472.96
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class PipeCuts {
	public double probability(int[] weldLocations, int L) {
		int cnt = 0, all = 0;
		int N = weldLocations.length;

		Arrays.sort(weldLocations);

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				all += 1;
				if (weldLocations[i] > L || weldLocations[j] - weldLocations[i] > L || 100 - weldLocations[j] > L) {
					cnt += 1;
				}
			}
		}
		return cnt / (double) all;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
