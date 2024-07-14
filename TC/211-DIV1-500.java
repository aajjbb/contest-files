// 2012-08-06T22:49:03+01:00 - 174.37
import java.util.*;
import java.math.*;
import java.awt.Point;

public class grafixMask {
	public int[] dx = {1,  0, -1, 0};
	public int[] dy = {0, -1,  0, 1};
	public int[] sortedAreas(String[] rectangles) {
		boolean[][] used = new boolean[400][600];
		int[][] mask = new int[400][600];

		for(int i = 0; i < rectangles.length; i++) {
			String[] tmp = rectangles[i].split("\\s");
			int x1 = d(tmp[0]), y1 = d(tmp[1]), x2 = d(tmp[2]), y2 = d(tmp[3]);
			for(int x = Math.min(x1, x2); x <= Math.max(x1, x2); x++) {
				for(int y = Math.min(y1, y2); y <= Math.max(y1, y2); y++) {
					mask[x][y] = 1; used[x][y] = true;
				}
			}
		}
		List<Integer> helper = new ArrayList<Integer>();
		for(int i = 0; i < 400; i++) {
			for(int j = 0; j < 600; j++) {
				if(used[i][j] == false && mask[i][j] == 0) {
					Stack<Point> s = new Stack<Point>();
					Set<Point> mem = new HashSet<Point>();
					s.push(new Point(i, j));
					while(!s.isEmpty()) {
						Point tmp = s.pop(); mem.add(tmp);
						used[tmp.x][tmp.y] = true;
						for(int x = 0; x < 4; x++) {
							int si = tmp.x + dx[x];
							int sj = tmp.y + dy[x];

							if(si >= 0 && si < 400 && sj >= 0 && sj < 600 && used[si][sj] == false && mask[si][sj] == 0) {
								s.push(new Point(si, sj));
							}
						}
					}
					helper.add(mem.size());
				}
			}
		}
		Collections.sort(helper);
		int[] ans = new int[helper.size()];
		for(int i = 0; i < helper.size(); i++) ans[i] = (Integer) helper.get(i);
		return ans;
	}
	public int d(String s) {
		return Integer.parseInt(s);
	}
}


// Powered by FileEdit
