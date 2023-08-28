// Submitted 2012-09-14 00:20:45

import java.util.*;

public class SpidersOnTheGrid {
	public int find(String[] A) {
		int ans = 0, N = A.length, M = A[0].length();
		int[][] occupy = new int[N][M];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(A[i].charAt(j) == 'N') {
					if(i - 1 >= 0) occupy[i-1][j] += 1;
				}
				if(A[i].charAt(j) == 'S') {
					if(i + 1 <  N) occupy[i+1][j] += 1;
				}
				if(A[i].charAt(j) == 'E') {
					if(j + 1 < M) occupy[i][j+1] += 1;
				}
				if(A[i].charAt(j) == 'W') {
					if(j - 1 >= 0) occupy[i][j-1] += 1;
				}
			}
		}
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(occupy[i][j] == 0) ans += 1;
		return ans;
	}
}