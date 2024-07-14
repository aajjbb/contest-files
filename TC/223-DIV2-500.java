// 02-07-2012 12:18:07+01:00	Submit	aajjbb	500	498.77
import java.util.*;

public class BlackAndRed {
	public int cut(String deck) {
		int N = deck.length();

		for(int i = 0; i < N; i++) {
			int r = 0, b = 0, ct = 0;
			for(int j = i; j < i + N; j++) {
				if(deck.charAt(j % N) == 'R') {
					r++;
				} else {
					b++;
				}
				if(r > b) ct++;
			}
			if(ct == 0) return i;
		}
		return N;
	}
}

// Powered by FileEdit