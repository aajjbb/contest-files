import java.util.*;
import java.awt.Point;
import java.math.*;

public class ProgrammingRobots {
	public final int[] dx = {0, 0, -1, 1};
	public final int[] dy = {-1, 1, 0, 0};
	public int numberOfRobots(String[] maze) {
		int ans = 0, N = maze.length, M = maze[0].length();
			
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(maze[i].charAt(j) == '#') {
					continue;
				}
				boolean walled = false;
				
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					
					if (ni < 0 || nj < 0 || ni >= N || nj >= M || maze[ni].charAt(nj) == '#') {
						walled = true;
					}
				}
				
				if (!walled) {
					continue;
				}
				int local_ans = dfs(i, j, N, M, maze, new boolean[N][M]);
				//System.err.println();
				//System.err.println(i + " " + j + " " + local_ans);
				ans = Math.max(ans, local_ans);				
			}
		}
		
		return ans;
	}	
	public int dfs(int i, int j, int N, int M, String[] maze, boolean[][] vis) {
		if(i < 0 || j < 0 || i >= N || j >= M || maze[i].charAt(j) == '#' || vis[i][j] == true) return 0;
		
		vis[i][j] = true;
			
		int ans = 0;
			
		if(maze[i].charAt(j) == 'R') {
			ans += 1;
		}
		
		for(int x = 0; x < 4; x++) {
			int xi = i + dx[x];
			int yi = j + dy[x];
			
			ans += dfs(xi, yi, N, M, maze, vis);
		}
		//System.err.println(i + " " + j + "  " + ans);
		return ans;
	}
}

// Powered by FileEdit
