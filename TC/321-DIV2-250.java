// 09-13-2012 21:07:30+01:00	Submit	aajjbb	250	182.24
import java.util.*;
import java.math.*;

public class KDoubleSubstrings {
	public int howMuch(String[] str, int x) {
		String big = "";
		for(String s: str) big += s;
		int ans = 0;
		for(int i = 0; i < big.length(); i++) {
			for(int j = i; j <= big.length(); j++) if((j - i != 0) && (j - i) % 2 == 0) {
				String cmp = big.substring(i, j);
				int diff = 0;
				for(int k = 0; k < cmp.length()/2; k++) {
					if(cmp.charAt(k) != cmp.charAt((cmp.length()/2)+k)) diff += 1;
				}
				if(diff <= x) {
					ans += 1;
				}
			}
		}
		return ans;
	}
}

// Powered by FileEdit