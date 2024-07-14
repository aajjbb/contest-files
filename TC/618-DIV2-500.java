// Submitted - 2014-04-25 04:35:31
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class LongWordsDiv2 {
	public String find(String word) {
		int N = word.length();
		boolean ok = true;


		for (int i = 0; i < N - 1; i++) {
			if (word.charAt(i) == word.charAt(i + 1)) {
				ok = false;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = i + 2; j < N; j++) if (word.charAt(i) == word.charAt(j)) {
				for (int k = i + 1; k < j; k++) {
					for (int l = j + 1; l < N; l++) {
						if (word.charAt(k) == word.charAt(l)) {
							ok = false;
						}
					}
				}
			}
		}
		return ok ? "Likes" : "Dislikes";
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!