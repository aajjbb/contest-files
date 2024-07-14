// 09-04-2012 19:37:28+01:00	Submit	aajjbb	250	248.65
import java.util.*;
import java.math.*;

public class EllipseCoverage {
	public int calculateCoverage(int x1, int y1, int x2, int y2, int d) {
		int ans = 0;
		for(int i = -400; i <= 400; i++) {
			for(int j = -400; j <= 400; j++) {
				double distA = (double) Math.hypot(x1 - i, y1 - j);
				double distB = (double) Math.hypot(x2 - i, y2 - j);

				if(distA + distB < d) {
					ans += 1;
				}
			}
		}
		return ans;
	}
}


// Powered by FileEdit