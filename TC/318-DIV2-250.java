// 09-21-2012 13:23:21+01:00	Submit	aajjbb	250	233.53
import java.util.*;
import java.math.*;

public class BiggestRectangleEasy {
	public int findArea(int N) {
		int ans = 0;
		for(int i = 1; i <= N/2; i++) {
			if((N - (i*2)) % 2 == 0) {
				ans = Math.max(ans, i * ((N-(i*2)) / 2));
			} else {
				ans = Math.max(ans, i * (((N-1)-(i*2)) / 2));
			}
		}
		return ans;
	}
}


// Powered by FileEdit