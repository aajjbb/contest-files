// 12-17-2013 20:20:15+01:00	Submit	aajjbb	250	171.26
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BalancedGame {
	public int result(String[] conflicts, int p, int q)	{
		int i;
		int j;

		int N = conflicts.length;

		for (i = 0; i < N; i++) {
			int uw = 0;
			int ul = 0;

			for (j = 0; j < N; j++) if (i != j) {
				if (conflicts[i].charAt(j) == 'W') {
					uw += 1;
				}
				if (conflicts[i].charAt(j) == 'L') {
					ul += 1;
				}
			}

			int per_win = (int) Math.ceil((N - 1) * p / 100.0);
			int per_los = (int) Math.ceil((N - 1) * q / 100.0);

			if (uw < per_win || ul < per_los) {
				return i;
			}

		}

		return -1;
	}
}
//Powered by [KawigiEdit] 2.0!
