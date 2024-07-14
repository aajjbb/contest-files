// 06-17-2013 05:35:29+01:00	Submit	aajjbb	250	245.58
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Sortness
{
	public double getSortness(int[] a)
	{
		int i, j, N = a.length;
		double ans = 0.0;

		for (i = 0; i < N; i++) {
			for (j = i - 1; j >= 0; j--) {
				if (a[j] > a[i]) ans += 1;
			}
			for (j = i + 1; j < N; j++) {
				if (a[j] < a[i]) ans += 1;
			}
		}

		return ans / N;
	}
}
//Powered by [KawigiEdit] 2.0!