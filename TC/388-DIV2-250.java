// 09-04-2012 19:45:42	Submit	aajjbb	250	242.03
import java.util.*;
import java.math.*;

public class MonotoneSequence {
	public int longestMonotoneSequence(int[] seq) {
		int ans = 0, n = seq.length, len;
		for(int i = 0; i < n; i++) {
			len = 1;
			for(int j = i + 1; j < n; j++) {
				if(seq[j] <= seq[j - 1]) break;
				len++;
			}
			ans = Math.max(ans, len);
			len = 1;
			for(int j = i + 1; j < n; j++) {
				if(seq[j] >= seq[j - 1]) break;
				len++;
			}
			ans = Math.max(ans, len);
		}
		return ans;
	}
}


// Powered by FileEdit