// 09-21-2012 12:36:38+01:00	Submit	aajjbb	500	472.48
import java.util.*;
import java.math.*;

public class WinningRecord {
	public int[] getBestAndWorst(String games) {
		int[] ans = new int[2];
		int win = 0, lose = 0;
		double mem_max = 0.0, mem_min = 1.0, EPS = 1e-10;

		for(int i = 0; i < games.length(); i++) {
			if(games.charAt(i) == 'W') win++;
			else lose++;

			if(i >= 2) {
				double percent_max = (double) win / (double) (win + lose);
				if(percent_max > mem_max - EPS) {
					mem_max = percent_max;
					ans[0] = i + 1;
				}
				if(percent_max < mem_min + EPS) {
					mem_min = percent_max;
					ans[1] = i + 1;
				}
			}
		}
		return ans;
	}
}


// Powered by FileEdit