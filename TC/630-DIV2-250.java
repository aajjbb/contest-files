// Submitted - 2014-08-22 04:58:59
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class DoubleLetter {
	public String ableToSolve(String S) {
		for (  ; true; ) {
			boolean ok = false;
			for (int i = 0; !ok && i < S.length() - 1; i++) {
				if (S.charAt(i) == S.charAt(i + 1)) {
					S = S.substring(0, i) + S.substring(i + 2);
					ok = true;
				}
			}
			if (!ok) break;
		}


		return S.isEmpty() ? "Possible" : "Impossible";
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!