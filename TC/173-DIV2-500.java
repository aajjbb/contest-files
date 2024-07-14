// 04-20-2013 05:10:42+01:00	Submit	aajjbb	500	346.45
import java.util.*;
import java.math.*;

public class WordForm {
	public String getSequence(String word) {
		String ans = "";

		word = word.toLowerCase();

		for(int i = 0; i < word.length(); i++) {
			boolean state = isVowel(word, i);
			int j = i;
			while(j < word.length() && isVowel(word, j) == state) {
				j += 1;
			}
			if(state) {
				ans += "V";
			} else {
				ans += "C";
			}
			i = j - 1;
		}

		return ans;
	}
	boolean isVowel(String haysack, int index) {
		if("aeiou".contains(""+haysack.charAt(index))) return true;
		if(haysack.charAt(index) == 'y') {
			if(index == 0) return false;
			if(isVowel(haysack, index - 1)) return false;
			return true;
		}
		return false;
	}
}

// Powered by FileEdit