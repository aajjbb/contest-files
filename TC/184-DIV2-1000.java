// 07-28-2012 21:29:00+01:00	Submit	aajjbb	1000	431.62
import java.util.*;

public class TeamBuilder {
	public boolean visited[];
	public int[] specialLocations(String[] paths) {
		int N = paths.length, count;
		int[] ans = new int[2];
		visited = new boolean[N];

		for(int i = 0; i < N; i++) {
			Arrays.fill(visited, false);
			dfs(i, N, visited, paths, 0);
			count = 0;
			for(int j = 0; j < N; j++) if(visited[j]) count += 1;
			if(count == N) ans[0]++;
			Arrays.fill(visited, false);
			dfs(i, N, visited, paths, 1);
			count = 0;
			for(int j = 0; j < N; j++) if(visited[j]) count += 1;
			if(count == N) ans[1]++;
		}
		return ans;
	}
	public void dfs(int x, int N, boolean[] visited, String[] paths, int check) {
		visited[x] = true;
		for(int i = 0; i < N; i++) if(!visited[i]) {
			if(check == 0) {
				if(paths[x].charAt(i) == '1') {
					dfs(i, N, visited, paths, check);
				}
			} else {
				if(paths[i].charAt(x) == '1') {
					dfs(i, N, visited, paths, check);
				}
			}
		}
	}
}

// Powered by FileEdit