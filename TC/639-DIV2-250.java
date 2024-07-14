// Submitted - 2014-11-28 18:42:07
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ElectronicPetEasy {
	public String isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
		Set<Integer> s1 = new HashSet<Integer>();
		Set<Integer> s2 = new HashSet<Integer>();

		for (int i = st1, cnt = 0; cnt < t1; i += p1, cnt += 1) {
			s1.add(i);
		}
		for (int i = st2, cnt = 0; cnt < t2; i += p2, cnt += 1) {
			s2.add(i);
		}

		for (Integer i: s1) {
			if (s2.contains(i)) {
				return "Difficult";
			}
		}

		return "Easy";
	}
}

//Powered by [KawigiEdit] 2.0!
