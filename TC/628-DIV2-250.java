// Submitted - 2014:08:03 20:27:17
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class BishopMove {
	public int[] dx = new int[] {1,  1, -1, -1};
	public int[] dy = new int[] {1, -1,  1, -1};

	public int howManyMoves(int r1, int c1, int r2, int c2) {
		boolean ok = false;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = r1 + (i * dx[j]);
				int ny = c1 + (i * dy[j]);


				if (nx >= 0 && nx <= 7 && ny >= 0 && ny <= 7 && Math.abs(nx - r2) == Math.abs(ny - c2)) {
					if (nx == r2 && ny == c2) {
						return i == 0 ? 0 : 1;
					} else {
						ok = true;
					}
				}
			}
		}
		return ok ? 2 : -1;
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
