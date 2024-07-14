// 09-21-2012 11:55:49+01:00	Submit	aajjbb	250	248.86
import java.util.*;
import java.math.*;

public class YahtzeeScore {
	public int maxPoints(int[] toss) {
		int ans = 0;
		for(int x = 1; x <= 6; x++) {
			int tmp = 0;
			for(int i = 0; i < toss.length; i++) {
				if(toss[i] == x) tmp += x;
			}
			ans = Math.max(ans, tmp);
		}
		return ans;
	}
}


// Powered by FileEdit