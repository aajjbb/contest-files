// 09-22-2013 05:44:47+01:00	Submit	aajjbb	500	468.44
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class WordCompositionGame {
	public String score(String[] listA, String[] listB, String[] listC)	{
		int scoreA = 0;
		int scoreB = 0;
		int scoreC = 0;

		int i;

		Set<String> aSet = new HashSet<String>(Arrays.asList(listA));
		Set<String> bSet = new HashSet<String>(Arrays.asList(listB));
		Set<String> cSet = new HashSet<String>(Arrays.asList(listC));

		for (i = 0; i < listA.length; i++) {
			boolean bB = bSet.contains(listA[i]);
			boolean bC = cSet.contains(listA[i]);

			if (!bB && !bC) {
				scoreA += 3;
			} else if (bB && bC) {
				scoreA += 1;
			} else {
				scoreA += 2;
			}
		}

		for (i = 0; i < listB.length; i++) {
			boolean bA = aSet.contains(listB[i]);
			boolean bC = cSet.contains(listB[i]);

			if (!bA && !bC) {
				scoreB += 3;
			} else if (bA && bC) {
				scoreB += 1;
			} else {
				scoreB += 2;
			}
		}

		for (i = 0; i < listC.length; i++) {
			boolean bA = bSet.contains(listC[i]);
			boolean bB = aSet.contains(listC[i]);

			if (!bA && !bB) {
				scoreC += 3;
			} else if (bA && bB) {
				scoreC += 1;
			} else {
				scoreC += 2;
			}
		}

		return scoreA + "/" + scoreB + "/" + scoreC;
	}
}

//Powered by [KawigiEdit] 2.0!