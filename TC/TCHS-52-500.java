// 26-06-2012 15:12:15
import java.util.*;

public class RRSchedule {
	public int[] terminalTimes(int[] tasks) {
		int N = tasks.length, tot = 0;
		int[] ans = new int[N];
		
		for(; N > 0; ) {
			int min = Integer.MAX_VALUE, index = 0;
			for(int j = 0; j < tasks.length; j++) {
				if(tasks[j] > 0 && tasks[j] < min) {
					index = j;
					min = tasks[j];
				}
			}
			for(int j = 0; j < tasks.length; j++) {
				if(tasks[j] > 0) {
					tasks[j] -= (min - 1);
				}
			}
			tot += (min - 1) * N;
			for(int j = 0; j < tasks.length; j++) if(tasks[j] != 0) {
				tot += 1;
				tasks[j]--;
				if(tasks[j] == 0) {
					ans[j] = tot;
					N--;
				}				
			}
		}		
		return ans;
	}
}

// Powered by FileEdit
