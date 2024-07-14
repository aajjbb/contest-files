// 07-17-2013 23:07:28+01:00	Submit	aajjbb	500	418.34
import java.util.*;
import java.math.*;

public class PalindromeMaker {
	public String make(String baseString) {
		int i, N = baseString.length();

		char[] str = baseString.toCharArray();
		int[] cnt = new int[26];

		for (i = 0; i < N; i++) {
			cnt[str[i]-'A'] += 1;
		}

		int odds = 0;

		for (i = 0; i < 26; i++) {
			if (cnt[i] % 2 == 1) odds += 1;
		}

		if (odds > 1) {
			return "";
		} else {
			String ans = "";

			int id = -1;

			for (i = 0; i < 26; i++) {
				if (cnt[i] % 2 == 1) {
					id = i;

					while (cnt[i] > 1) {
						ans += (char) ('A' + i);
						cnt[i] -= 2;
					}
				} else {
					while (cnt[i] > 0) {
						ans += (char) ('A' + i);
						cnt[i] -= 2;
					}
				}
			}

			if (id != -1) {
				ans = ans + (char) ('A' + id) + reverse(ans);
			} else {
				ans = ans + reverse(ans);
			}

			return ans;
		}
	}

	public String reverse (String str) {
		return new StringBuilder(str).reverse().toString();
	}
}

// Powered by FileEdit