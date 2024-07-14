// 06-02-2013 20:54:49+01:00	Submit	aajjbb	600	228.92
import java.util.*;
import java.math.*;

public class TeXLeX {
	public int[] getTokens(String input) {
		List<Integer> pre_ans = new ArrayList<Integer>();

		int i, N = input.length();

		while (N > 0) {
			if (N >= 2 && input.charAt(0) == '^' && input.charAt(1) == '^') {
				if (4 <= N && isLowerHex(input.charAt(2)) && isLowerHex(input.charAt(3))) {
					input = (char) Integer.parseInt(input.substring(2, 4), 16) + input.substring(4);
					N = input.length();
					continue;
				} else if (3 <= N && input.charAt(2) > 63) {
					input = (char) (input.charAt(2)-64) + input.substring(3);
					N = input.length();
					continue;
				} else if (3 <= N && input.charAt(2) < 64) {
					input = (char) (input.charAt(2)+64) + input.substring(3);
					N = input.length();
					continue;
				}
			}
			pre_ans.add((int) input.charAt(0));
			input = input.substring(1);
			N = input.length();
		}

		int[] ans = new int[pre_ans.size()];

		for (i = 0; i < pre_ans.size(); i++) ans[i] = pre_ans.get(i);

		return ans;
	}

	public boolean isLowerHex(char c) {
		return "0123456789abcdef".contains(""+c);
	}
}

// Powered by FileEdit