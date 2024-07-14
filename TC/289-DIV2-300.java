// 08-30-2012 20:30:37+01:00	Submit	aajjbb	300	278.73
import java.util.*;

public class ObjectFall {
	public int howLong(int x, int y, String[] obstacles) {
		int ans = 0, n = obstacles.length;
		int[] height = new int[n];
		int[] start_x = new int[n];
		int[] end_x = new int[n];
		boolean[] passed = new boolean[n];

		for(int i = 0; i < n; i++) {
			String[] helper = obstacles[i].split("\\s");
			height[i] = Integer.parseInt(helper[0]);
			start_x[i] = Integer.parseInt(helper[1]);
			end_x[i] = Integer.parseInt(helper[2]);
		}

		while(y > 0) {
			for(int i = 0; i < n; i++) {
				if(height[i] == y && x >= start_x[i] && x <= end_x[i]) {
					x = end_x[i];
					ans += 5;
				}
			}
			y -= 1; ans += 1;
		}
		return ans;
	}
}

// Powered by FileEdit