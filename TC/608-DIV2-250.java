// Submitted 2014-02-07 17:58:55

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class OneDimensionalRobotEasy {
	public int finalPosition(String commands, int A, int B) {
		int pos = 0;

		for (char s: commands.toCharArray()) {
			if (s == 'R') {
				if (pos + 1 <= B) {
					pos += 1;
				}
			} else {
				if (pos - 1 >= -A) {
					pos -= 1;
				}
			}
		}

		return pos;
	}
}
//Powered by [KawigiEdit] 2.0!