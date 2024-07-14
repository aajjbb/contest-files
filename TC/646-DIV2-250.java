// 2015-01-21 03:39:15
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class TheConsecutiveIntegersDivTwo {
	public int find(int[] numbers, int k) {
		if (k == 1) {
			return 0;
		} else {
			Arrays.sort(numbers);

			int ans = Integer.MAX_VALUE;

			for (int i = 1; i < numbers.length; i++) {
				ans = Math.min(ans, numbers[i] - numbers[i - 1] - 1);
			}

			return ans;
		}
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
