// 09-21-2012 12:55:43+01:00	Submit	aajjbb	250	207.56
import java.util.*;
import java.math.*;

public class ThrowTheBall {
	public int timesThrown(int N, int M, int L) {
		int x, times = 0, index = 0;
		int[] get = new int[N];

		while(true) {
			get[index] += 1;
			if(get[index] >= M) break;
			times += 1;
			if((get[index]) % 2 == 0) {
				for(x = 0; x < L; x++) {
					index += 1;
					if(index == N) index = 0;
				}
			} else {
				for(x = 0; x < L; x++) {
					index -= 1;
					if(index == -1) index = N-1;
				}
			}
		}
		return times;
	}
}


// Powered by FileEdit