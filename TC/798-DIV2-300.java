import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class SyllableCountEstimator {
	public int estimate(String W) {
		int count = 0;
		String vowels = "aeiou";
		String[] longerVowels = {"au", "oa", "oo", "iou"};

		for (int i = 0; i < vowels.length(); i++) {
			for (int j = 0; j < W.length(); j++) {
				if (vowels.charAt(i) == W.charAt(j)) {
					count += 1;
				}
			}
		}

		for (int i = 0; i < longerVowels.length; i++) {
			for (int j = 0; j < W.length(); j++) {
				if (j + longerVowels[i].length() > W.length()) {
					continue;
				}
				if (longerVowels[i].equals(W.substring(j, j + longerVowels[i].length()))) {
					count -= 1;
				}
			}
			//count -= W.split(longerVowels[i], -1).length - 1;
		}

		if (W.charAt(W.length() - 1) == 'e') {
			count -= 1;
		}

		if (W.endsWith("le") && W.length() > 2 && !vowels.contains(""+W.charAt(W.length() - 3))) {
			count += 1;
		}

		return Math.max(1, count);
	}
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!