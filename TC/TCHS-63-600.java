// 2014-07-08T04:34:55+01:00
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class Telltale {
	public int doNotTellTheTruth(int n, int[] a, String[] parties) {
		Set<Integer> notAble = new HashSet<Integer>();

		for (int i = 0; i < a.length; i++) {
			notAble.add(a[i]);
		}
		for (int run = 0; run < 50; run++) {
			for (int i = 0; i < parties.length; i++) {
				String[] st = parties[i].split(" ");
				boolean has = false;

				for (String s: st) {
					if (notAble.contains(Integer.parseInt(s))) {
						has = true;
					}
				}

				if (has) {
					for (String s: st) {
						notAble.add(Integer.parseInt(s));
					}
				}
			}
		}
		int ans = 0;

		for (int i = 0; i < parties.length; i++) {
			boolean valid = true;
			String[] st = parties[i].split(" ");

			for (String s: st) {
				if (notAble.contains(Integer.parseInt(s))) {
					valid = false;
				}
			}
			if (valid) ans += 1;
		}

		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
