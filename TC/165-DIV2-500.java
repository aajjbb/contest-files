// 03-09-2013 04:28:50+01:00	Submit	aajjbb	500	220.31
import java.util.*;
import java.math.*;

public class ParallelSpeedup {
	public int numProcessors(int k, int overhead) {
		int used = 0;
		long all = Long.MAX_VALUE;

		for(int i = 1; i <= k; i++) {
			long time = 0L;
			if(k % i == 0) {
				time = (k / i) + (overhead * i * (i - 1) / 2);
			} else {
				time = 1 + (k / i) + (overhead * i * (i - 1) / 2);
			}
			if(time < all) {
				all = time;
				used = i;
			}
			if(time > k) break;
		}

		return used;
	}
}


// Powered by FileEdit
