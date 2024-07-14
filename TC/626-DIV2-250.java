// Submitted - 2014:06:28 20:29:48
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class SumOfPower {
	public int findSum(int[] array) {
		int sum = 0;
		int N = array.length;

		for (int i = 0; i < N; i++) {
			int s = 0;
			for (int j = i; j < N; j++) {
				s += array[j];
				sum += s;
			}
		}

		return sum;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
