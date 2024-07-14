// 09-24-2014 19:04:31+01:00	Submit	aajjbb	500	393.79
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class CarolsSinging {
	public int choose(String[] lyrics) {
		int N = lyrics.length;
		int M = lyrics[0].length();

		int ans = Integer.MAX_VALUE;

		for (int i = 1; i < (1 << M); i++) {
			boolean[] used = new boolean[N];
			int cnt = 0;

			for (int j = 0; j < M; j++) {
				if ((i & (1 << j)) != 0) {
					for (int k = 0; k < N; k++) {
						if (lyrics[k].charAt(j) == 'Y') {
							if (!used[k]) {
								used[k] = true;
								cnt += 1;
							}
						}
					}
				}
			}

			if (cnt == N) {
				ans = Math.min(ans, Integer.bitCount(i));
			}
		}
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
