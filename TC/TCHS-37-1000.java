// 2012-01-09T15:41:38+01:00
import java.util.*;

public class SumoTournament {
	public int maxWeight(int[] weight, int ave) {
		int N = weight.length, mx = 0;

		for(int i = 0; i < (1 << N); i++) {
			int actual = 0, ct = 0, tr = 0;
			for(int j = 0; j < N; j++) {
				if((i & (1 << j)) > 0) {
					tr = Math.max(tr, weight[j]);
					actual += weight[j];
					ct += 1;
				}
			}
			if(ct != 0 && actual % ct == 0 && ave == actual / ct) {
				mx = Math.max(mx, tr);
			}
		}
		if(mx == 0) return -1;
		return mx;
	}
}

// Powered by FileEdit