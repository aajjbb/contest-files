// Submitted - 2015:02:18 03:58:58
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class TaroJiroDividing {
	public int getNumber(int A, int B) {
		Set<Integer> sA = new HashSet<Integer>();
		Set<Integer> sB = new HashSet<Integer>();

		while (true) {
			sA.add(A);
			if (A % 2 == 1) break;
			A /= 2;
		}
		while (true) {
			sB.add(B);
			if (B % 2 == 1) break;
			B /= 2;
		}
		sA.retainAll(sB);
		return sA.size();
	}
	public void debug(Object ... obj) {
		System.out.println(Arrays.deepToString(obj));
	}
}

//Powered by [KawigiEdit] 2.0!
