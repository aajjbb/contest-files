// 2013-03-02T05:14:34+01:00
import java.util.*;
import java.math.*;

public class BenfordsLaw {
	public int questionableDigit(int[] transactions, int threshold) {
		int N = transactions.length;
		int[] freq = new int[10];

		for(int i = 0; i < N; i++) {
			String rep = "" + transactions[i];
			freq[rep.charAt(0) - '0'] += 1;
		}
		for(int i = 1; i <= 9; i++) {
			double now = Math.log10(1. + 1./(double)i) * N;
			if(freq[i] >= threshold * now || freq[i] <= now / threshold) {
				return i;
			}
		}
		return -1;
	}
}

// Powered by FileEdit