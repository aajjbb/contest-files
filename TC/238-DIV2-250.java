// 04-06-2013 20:30:41+01:00	Submit	aajjbb	250	248.08
import java.util.*;
import java.math.*;

public class ArrayHash {
	public int getHash(String[] input) {
		int ans = 0;

		for(int i = 0; i < input.length; i++) {
			for(int j = 0; j < input[i].length(); j++) {
				ans += (input[i].charAt(j) - 'A') + i + j;
			}
		}

		return ans;
	}
}

// Powered by FileEdit