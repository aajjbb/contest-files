// 01-04-2012 20:56:21+01:00	Submit	aajjbb	900	855.98
import java.util.*;

public class NumericalSequence {
	public int makePalindrome(int[] seq) {
		int counter = 0, N = seq.length;

		for(int i = 0, j = N - 1; i < j; ) {
			boolean ok = false;
			if(seq[i] < seq[j]) {
				ok |= true;
				i++;
				seq[i] += seq[i - 1];
			} else if(seq[j] < seq[i]) {
				ok |= true;
				j--;
				seq[j] += seq[j + 1];
			} else {
				i++;
				j--;
			}
			if(ok) counter++;
		}

		return counter;
	}
}

// Powered by FileEdit
