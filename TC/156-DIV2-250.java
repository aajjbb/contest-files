// 2012-09-30T21:30:50+01:00
import java.util.*;

public class DiskSpace {
	public int minDrives(int[] used, int[] total) {
		int min = 0, all = 0, N = total.length;
		for(int i = 0; i < N; i++) {
			all += used[i];
		}
		Arrays.sort(total);
		for(int i = N - 1; i >= 0; i--) {
			all -= total[i];
			min += 1;
			if(all <= 0) break;
		}
		return min;
	}
}


// Powered by FileEdit