// Submitted - 2015:05:22 03:23:51
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class RectangleCoveringEasy {
	public int solve(int holeH, int holeW, int boardH, int boardW) {
		return (fine(holeH, holeW, boardH, boardW) || fine(holeH, holeW, boardW, boardH)) ? 1 : -1;
	}
	public boolean fine(int a, int b, int x, int y) {
		if (x >= a && y >= b) {
			if (x == a && y == b) {
				return false;
			} else {
				return true;
			}
		} else {
			return false;
		}
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
