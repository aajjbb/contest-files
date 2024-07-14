// 10-20-2014 05:37:32+01:00	Submit	aajjbb	250	177.14
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class TwoRotationCypher {
	public String encrypt(int firstSize, int firstRotate, int secondRotate, String message) {
		String ans = "";

		for (char c: message.toCharArray()) {
			if (c == ' ') {
				ans += " ";
			} else {
				int pos = c - 'a';

				if (pos < firstSize) {
					ans += (char) ('a' + ((pos + firstRotate) % firstSize));
				} else {
					ans += (char) ('a' + firstSize + ((pos + secondRotate - firstSize) % (26 - firstSize)) % (26 - firstSize));
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
