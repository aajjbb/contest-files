// 09-23-2014 18:37:53+01:00	Submit	aajjbb	250	249.07
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ComboLength {
	public int howLong(String moves) {
		int ans = 0;
		int N = moves.length();
		char[] L = moves.toCharArray();

		for (int i = 0; i < N; i++) {
			int j = i + 1;
			int len = 1;

			while (j < N && L[i] == L[j]) {
				j += 1;
				len += 1;
			}
			ans = Math.max(ans, len);
			i = j - 1;
		}

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
