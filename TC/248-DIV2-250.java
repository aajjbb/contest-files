// 09-06-2012 15:48:03+01:00	Submit	aajjbb	250	246.40
import java.util.*;
import java.math.*;

public class SyllableCounter {
	public int countSyllables(String word) {
		Set<Character> s = new HashSet<Character>();
		s.add('A'); s.add('E'); s.add('I'); s.add('O'); s.add('U');
		int ans = 0;
		for(int i = 0; i < word.length(); i++) if(s.contains(word.charAt(i))) {
			int j = i + 1;
			while(j < word.length() && s.contains(word.charAt(j))) j++;
			i = j - 1;
			ans += 1;
		}
		return ans;
	}
}


// Powered by FileEdit