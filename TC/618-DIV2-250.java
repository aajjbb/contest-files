// Submitted - 2014-04-25 04:28:24
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class WritingWords {
	public int write(String word) {
		int ans = 0;

		for (char c: word.toCharArray()) {
			ans += c - 'A' + 1;
		}
		return ans;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!