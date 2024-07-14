// 10-01-2012 04:28:11+01:00	Submit	aajjbb	500	458.54
import java.util.*;

public class BinaryCardinality {
	public int[] arrange(int[] numbers) {
		int N = numbers.length;
		Integer[] array = new Integer[N];
		for(int i = 0; i < N; i++) array[i] = (Integer) numbers[i];
		Arrays.sort(array, new Comparator<Integer>() {
			public int compare(Integer a, Integer b) {
				int bin_a = countOnes(Integer.toBinaryString(a));
				int bin_b = countOnes(Integer.toBinaryString(b));

				if(bin_a < bin_b) return -1;
				if(bin_a > bin_b) return 1;
				return a.compareTo(b);
			}
		});
		for(int i = 0; i < N; i++) numbers[i] = (int) array[i];
		return numbers;
	}
	public int countOnes(String s) {
		int ans = 0;
		for(char c: s.toCharArray()) if(c == '1') ans += 1;
		return ans;
	}
}

// Powered by FileEdit
