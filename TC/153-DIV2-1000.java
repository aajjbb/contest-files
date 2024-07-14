// 2012-01-10T10:44:54+01:00
import java.util.*;

public class PickTeam {
	public String[] pickPeople(int teamSize, String[] people) {
		int N = people.length, mx = Integer.MIN_VALUE;

		int[][] values = new int[N][N];
		String[] n = new String[N];

		for(int i = 0; i < N; i++) {
			String[] t = people[i].split("\\s");
			n[i] = t[0];
			for(int j = 0; j < N; j++) {
				values[i][j] = Integer.parseInt(t[j + 1]);
			}
		}

		String[] ans = new String[teamSize];

		for(int i = 0; i < (1 << N); i++) {
			if(Integer.bitCount(i) == teamSize) {
				int sum = 0;
				for(int j = 0; j < N; j++) {
					for(int k = 0; k < N; k++) {
						if(((1 << j) & i) != 0 && ((1 << k) & i) != 0) {
							sum += values[j][k];
						}
					}
				}
				if(sum > mx) {
					mx = sum;
					int pivot = 0;
					for(int k = 0; k < N; k++) {
						if(((1 << k) & i) != 0) {
							ans[pivot++] = n[k];
						}
					}
				}
			}
		}
		Arrays.sort(ans);
		return ans;
	}
}

// Powered by FileEdit