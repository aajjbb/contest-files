// Submitted 2014-02-15 16:09:40

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class MysticAndCandiesEasy {
	public int minBoxes(int C, int X, int[] high) {
		int N = high.length;

		Arrays.sort(high);

		for (int i = 0; i < N; i++) {
			C -= high[i];
			System.out.println(C);

			if (C < X) {
				return N - i;
			}
		}

		return -1;
	}

	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!