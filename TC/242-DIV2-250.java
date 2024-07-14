// 06-26-2013 04:49:21+01:00	Submit	aajjbb	250	248.73
import java.util.*;
import java.math.*;

public class TeamSplit {
	public int difference(int[] strengths) {
		int i, N = strengths.length, A = 0, B = 0;

		Arrays.sort(strengths);

		for (i = 0; i < N; i++) {
			if (i % 2 == 0) A += strengths[i];
			else B += strengths[i];
		}

		return Math.abs(A - B);
	}
}

// Powered by FileEdit