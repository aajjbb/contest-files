// 10-20-2014 05:18:08+01:00	Submit	aajjbb	500	487.07
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class TrueStatements {
	public int numberTrue(int[] statements) {
		for (int i = 50; i >= 0; i--) {
			int cnt = 0;
			for (int s: statements) {
				if (s == i) {
					cnt += 1;
				}
			}
			if (cnt == i) return i;
		}
		return -1;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
