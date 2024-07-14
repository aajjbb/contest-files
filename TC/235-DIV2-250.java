// 10-03-2012 01:36:29+01:00	Submit	aajjbb	250	246.98
import java.util.*;

public class NoisySensor {
	public int[] medianFilter(int[] data) {
		int N = data.length;
		int[] ans = new int[N];

		ans[0] = data[0];
		ans[N-1] = data[N-1];

		for(int i = 1; i < N - 1; i++) {
			ans[i] = median(data[i - 1], data[i], data[i + 1]);
		}
		return ans;
	}
	public int median(int a, int b, int c) {
		int[] array = {a, b, c};
		Arrays.sort(array);
		return array[1];
	}
}


// Powered by FileEdit