// 06-23-2013 18:08:40+01:00	Submit	aajjbb	300	296.36
import java.util.*;
import java.math.*;

public class DancingSentence {
	public String makeDancing(String sentence) {
		int i, N = sentence.length(), ok = 0;

		char[] str = sentence.toCharArray();

		for (i = 0; i < N; i++) {
			if (Character.isLetter(str[i])) {
				if (ok % 2 == 0) {
					str[i] = Character.toUpperCase(str[i]);
				} else {
					str[i] = Character.toLowerCase(str[i]);
				}
				ok ^= 1;
			}
		}

		return new String(str);
	}
}

// Powered by FileEdit