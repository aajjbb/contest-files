// 07-10-2012 19:37:10+01:00	Submit	aajjbb	250	152.84
import java.util.*;

public class Reppity {
	public int longestRep(String input) {
		int l = 0;

		for(int i = 0; i < input.length(); i++) {
			for(int j = i; j < input.length(); j++) {
				String tmp = input.substring(i, j);
				int occ = 0;
				for(int k = 0; k + tmp.length() <= input.length(); k++) {
					if(input.substring(k, k + tmp.length()).equals(tmp)) {
						occ++;
						k = k + (tmp.length() > 0 ? tmp.length() - 1 : tmp.length());
					}
				}
				if(occ >= 2) {
					l = Math.max(l, tmp.length());
				}
			}
		}
		return l;
	}
}

// Powered by FileEdit