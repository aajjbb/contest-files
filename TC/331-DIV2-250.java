// 09-24-2014 20:15:17+01:00	Submit	aajjbb	250	75.00
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SantaGifts {
	public String[] distribute(String[] gifts, int N) {
		String[] ans = new String[N];
		int M = gifts.length;
		int[] used = new int[N];
		int pos = 0;

		Arrays.fill(ans, "");

		for (int i = 0; i < M; i++) {
			if (used[pos] < 4) {
				ans[pos] += gifts[i] + " ";
				used[pos] += 1;
			}
			pos = (pos + 1) % N;
		}

		for (int i = 0; i < N; i++) {
			ans[i] = ans[i].trim();
		}

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
