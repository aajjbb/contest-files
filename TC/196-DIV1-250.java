// 03-03-2014 17:53:06+01:00	Submit	aajjbb	250	169.99
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class ClapLight {
	public final double EPS = 1e-7;
	public int threshold(int[] back) {
		int N = back.length;

		for (int x = 0; x <= 1001; x++) {
			int low_cnt = 0;
			boolean ok = true;

			boolean[] out = new boolean[N];

			for (int i = 0; i < N; i++) {
				if (back[i] < x) {
					low_cnt += 1;
				} else {
					out[i] = true;
				}
			}

			for (int i = 0; i < N - 3; i++) {
				if (!out[i] && out[i + 1] && out[i + 2] && !out[i + 3]) {
					ok = false;
				}
			}
			if (low_cnt * 100.0 / (double) N > 50.0 && ok) {
				return x;
			}
		}
		return -1;
	}

	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!

