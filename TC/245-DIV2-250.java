// 10-01-2014 17:48:25+01:00	Submit	aajjbb	250	204.40
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Straights {
	public int howMany(int[] hand, int k) {
		int ans = 0;

		for (int i = 0; i < 13 - k + 1; i++) {
			int L = 1;

			for (int j = 0; j < k; j++) {
				L *= hand[i + j];
			}
			ans += L;
		}

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
