// 12-17-2013 19:45:47+01:00	Submit	aajjbb	500	345.06
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ListeningIn {
	public String probableMatch(String typed, String phrase) {
		int i = 0;
		int j = 0;

		String ans = "";

		int N = typed.length();
		int M = phrase.length();

		for ( ; j < M; ) {
			if (i < N && j < M && typed.charAt(i) == phrase.charAt(j)) {
				i += 1;
				j += 1;
			} else {
				ans += phrase.charAt(j);
				j += 1;
			}
		}

		if (j != M || i != N) ans = "UNMATCHED";

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
