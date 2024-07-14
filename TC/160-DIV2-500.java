// 2013-12-08T14:37:39+01:00
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Intersect {
	public int area(int[] x, int[] y) {
		int i;
		int N = x.length;

		int uy = Integer.MAX_VALUE;
		int ly = Integer.MIN_VALUE;
		int lx = Integer.MIN_VALUE;
		int rx = Integer.MAX_VALUE;

		for (i = 0; i < N; i += 2) {
			uy = Math.min(uy, Math.max(y[i], y[i + 1]));
			ly = Math.max(ly, Math.min(y[i], y[i + 1]));
			rx = Math.min(rx, Math.max(x[i], x[i + 1]));
			lx = Math.max(lx, Math.min(x[i], x[i + 1]));
		}

		if (ly > uy) ly = uy;
		if (lx > rx) lx = rx;

		System.out.println(lx + " " + uy + " " + rx + " " + ly);

		return (uy - ly) * (rx - lx);
	}
}
//Powered by [KawigiEdit] 2.0!
