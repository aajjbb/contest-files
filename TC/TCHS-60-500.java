import java.util.*;

public class TurnOnTheLights {
	public final int[] dx = {1, -1, 0, 0};
	public final int[] dy = {0, 0, -1, 1};
	public int countLights(String[] floor, int K, int row, int col) {
		int max = 0, N = floor.length, M = floor[0].length();
		
		for(int x = 0; x < 4; x++) {
			int ai = row, aj = col;
			int count = 0;
			boolean[][] vis = new boolean[N][M];
			for(int a = 0; a < K; a++) {
				ai += dx[x];
				aj += dy[x];
				
				if(ai >= 0 && ai < N && aj >= 0 && aj < M && floor[ai].charAt(aj) == 'Y') {
					vis[ai][aj] = true;
					for(int y = 0; y < 4; y++) {
						int tmi = ai + dx[y];
						int tmj = aj + dy[y];
						
						if(tmi >= 0 && tmj >= 0 && tmi < N && tmj < M && !vis[tmi][tmj] && floor[tmi].charAt(tmj) == 'Y') {
							vis[tmi][tmj] = true;
						}
					}
				}
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(vis[i][j]) count += 1;
				}
			}
			max = Math.max(count, max);
		}		
		return max;
	}
}

// Powered by FileEdit
