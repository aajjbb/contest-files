// 06-15-2011 19:00:36+01:00	Submit	aajjbb	250	204.45
import java.util.*;

public class InsideOut {
	public String unscramble(String line) {
		int n = line.length() / 2;

		String ans = "";

		for(int i = n - 1; i >= 0; i--) {
			ans += line.charAt(i);
		}
		for(int j = 2 * n - 1; j >= n; j--) {
			ans += line.charAt(j);
		}
	return ans;
	}
}

// Powered by FileEdit