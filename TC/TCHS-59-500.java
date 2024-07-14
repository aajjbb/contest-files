// 2012-05-10T00:27:35+01:00
import java.util.*;
import java.math.*;

public class EquilibriumPoints {
	public static final double EPS = 1e-10;
	public double[] getPoints(int[] x, int[] m) {
		int N = x.length;
		double[] ans = new double[N - 1];

		for(int i = 0; i < N - 1; i++) {
			double low = x[i], high = x[i + 1], mid = 0.0, sum = 0.0;
			while(high - low > EPS) {
				mid = (low + high) / 2;
				sum = 0.0;
				for(int j = 0; j < N; j++) {
					if(j <= i) {
						sum += (-1 * m[j]) / Math.pow(mid - x[j], 2);
					} else {
						sum += ( 1 * m[j]) / Math.pow(mid - x[j], 2);
					}
				}
				if(sum > 0) {
					high = mid;
				} else {
					low = mid;
				}
			}
			ans[i] = low;
		}
		return ans;
	}
}

// Powered by FileEdit
