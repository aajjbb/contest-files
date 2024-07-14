// 08-30-2015 17:57:16+01:00	Submit	aajjbb	250	247.80
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class DiamondHunt {
	public int countDiamonds(String mine) {
		int ans = 0;

		while (true) {
			boolean found = false;

			for (int i = 0; i < mine.length() - 1; i++) {
				if (mine.charAt(i) == '<' && mine.charAt(i + 1) == '>') {
					found = true;
					mine = mine.substring(0, i) + mine.substring(i + 2);
					ans += 1;
					break;
				}
			}
			if (!found) break;
		}

		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
