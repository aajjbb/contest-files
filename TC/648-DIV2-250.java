// Submited - 2015-02-19 23:49:09
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class KitayutaMart2 {
	public int numBought(int K, int T) {
		long spent = 0;
		int bought = 0;

		while (spent != T) {
			spent += Math.pow(2, bought) * K;
			bought++;
		}

		return bought;
	}

	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!
