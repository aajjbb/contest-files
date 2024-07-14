// 01-08-2013 19:32:18+01:00	Submit	aajjbb	500	150.00
import java.util.*;
import java.math.*;

public class DrawingMarbles {
	public double sameColor(int[] colors, int n) {
		double ans = 0.0;
		int all = 0;

		for(int i: colors) all += i;

		for(int i = 0; i < colors.length; i++) {
			int now = colors[i], ok = all;
			double tmp = 1.0;
			for(int j = 0; j < n; j++) {
				tmp *= (double) (now - j) / (ok - j);
			}
			ans += (double) tmp;
		}

		return (double) ans;
	}
}


// Powered by FileEdit
