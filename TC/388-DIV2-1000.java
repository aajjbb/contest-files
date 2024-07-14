// 09-04-2012 20:13:29	Submit	aajjbb	1000	999.99
import java.util.*;
import java.math.*;

public class SmoothNumbersHard {
	public int countSmoothNumbers(int N, int k) {
		int ans = N;
		boolean[] sieve = new boolean[N+1];
		boolean[] ok = new boolean[N+1];
		Arrays.fill(sieve, true);
		sieve[0] = sieve[1] = false;
		for(int i = 2; i <= N; i++) {
			if(sieve[i]) {
				for(int j = 2*i; j <= N; j += i) {
					sieve[j] = false;
				}
				if(i > k) {
					for(int j = i; j <= N; j += i) {
						if(!ok[j]) {
							ok[j] = true;
							ans -= 1;
						}
					}
				}
			}
		}
		return ans;
	}
}


// Powered by FileEdit