// 09-11-2012 21:07:18+01:00	Submit	aajjbb	250	233.91
import java.util.*;
import java.math.*;

public class MovingAverages {
	public int[] calculate(String[] times, int n) {
		int m = times.length;
		int[] to_s = new int[m];
		for(int i = 0; i < m; i++) {
			to_s[i] = (Integer.parseInt(times[i].substring(0, 2)) * 3600) + (Integer.parseInt(times[i].substring(3, 5)) * 60) + Integer.parseInt(times[i].substring(6, 8));
		}
		List<Integer> help = new ArrayList<Integer>();
		for(int i = 0; i + n <= m; i++) {
			int tmp = 0;
			for(int j = 0; j < n; j++) {
				tmp += to_s[i+j];
			}
			help.add(tmp/n);
		}
		int[] ans = new int[help.size()];
		for(int i = 0; i < help.size(); i++) ans[i] = help.get(i);
		return ans;
	}
}


// Powered by FileEdit
