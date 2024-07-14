// 09-14-2012 13:50:58+01:00	Submit	aajjbb	250	248.51
import java.util.*;
import java.math.*;

public class TestCurve {
	public int[] determineGrades(int[] scores) {
		int proportion = max(scores);

		for(int i = 0; i < scores.length; i++) {
			scores[i] = scores[i] * 100 / proportion;
		}
		return scores;
	}
	public int max(int[] s) {
		int ans = Integer.MIN_VALUE;
		for(int i: s) ans = Math.max(ans, i);
		return ans;
	}
}


// Powered by FileEdit
