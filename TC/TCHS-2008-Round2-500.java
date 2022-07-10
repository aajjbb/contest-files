import java.util.*;

public class TriangularSubsequence {
	public int longest(int[] a) {
		int l = 0;
		Arrays.sort(a);
		for(int i = 0; i < a.length + 1; i++) {
			for(int j = 0; j < a.length + 1; j++) {
				if(i <= j) {
					if(j - i >= 3 && a[j - 1] >= a[i] + a[i + 1]) {
						continue;
					}
					l = Math.max(l, j - i);
				}
			}
		}
		return l;
	}	
}


// Powered by FileEdit