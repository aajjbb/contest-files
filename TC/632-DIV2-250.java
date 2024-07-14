// Submitted - 2014:09:25 18:32:05
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class RunningAroundPark {
	public int numberOfLap(int N, int[] d) {
		int ans = 1, last = 0;
		int L = d.length;

		for (int i = 0; i < L; i++) {
			if (d[i] <= last) {
				ans += 1;
			}
			last = d[i];
		}

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
