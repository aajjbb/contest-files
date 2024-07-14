// 2013-02-21T21:06:23+01:00
import java.util.*;
import java.math.*;

public class ImageDithering {
	public int count(String dithered, String[] screen) {
		int ans = 0;
		Set<Character> set = new HashSet<Character>();

		for(char c: dithered.toCharArray()) set.add(c);

		for(int i = 0; i < screen.length; i++) {
			for(int j = 0; j < screen[i].length(); j++) {
				if(set.contains(screen[i].charAt(j))) ans += 1;
			}
		}
		return ans;
	}
}


// Powered by FileEdit