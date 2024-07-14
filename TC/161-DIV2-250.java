// 2013-03-07T17:09:51+01:00
import java.util.*;
import java.math.*;

public class CardCount {
	public String[] dealHands(int numPlayers, String deck) {
		String[] ans = new String[numPlayers];

		Arrays.fill(ans, "");

		for(int i = 0; i < deck.length(); i++) {
			ans[i % numPlayers] += deck.charAt(i);
		}

		int min = Integer.MAX_VALUE;

		for(String s: ans) min = Math.min(min, s.length());

		for(int i = 0; i < numPlayers; i++) {
			if(ans[i].length() > min) ans[i] = ans[i].substring(0, ans[i].length()-1);
		}

		return ans;
	}
}

// Powered by FileEdit