// Submitted - 2014:06:28 18:27:25
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class AddMultiply {
	public int[] makeExpression(int y) {
		int[] ans = new int[3];

		for (int i = -1000; i <= 1000; i++) {
			for (int j = -1000; j <= 1000; j++) {
				int x = y - i * j;

				if (x + i * j == y && i != 0 && i != 1 && j != 0 && j != 1 && x != 0 && x != 1 && x >= -1000 &&  x <= 1000) {
					ans[0] = i;
					ans[1] = j;
					ans[2] = x;
				}
			}
		}

		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
