// 10-11-2012 13:59:12+01:00 Submit	aajjbb	250	214.00
import java.util.*;
import java.math.*;

public class Cards {
    public String[] deal(int numPlayers, String deck) {
        String[] ans = new String[numPlayers];

        Arrays.fill(ans, "");

        if(numPlayers > deck.length()) return ans;

        for(int i = 0; i < deck.length(); i++) {
            ans[i % numPlayers] += deck.charAt(i);

        }
        int len = Integer.MAX_VALUE;
        for(String s: ans) {
            len = Math.min(len, s.length());
        }
        for(int i = 0; i < ans.length; i++) {
            ans[i] = ans[i].substring(0, len);
        }
        return ans;
    }
}


// Powered by FileEdit
