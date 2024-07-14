// 09-05-2012 22:27:55+01:00	Submit	aajjbb	250	245.63
import java.util.*;
import java.math.*;

public class StringSegment {
	public double average(String s) {
		double count = 0.0;
		for(int i = 0; i < s.length(); i++) {
			int j;
			for(j = i + 1; j < s.length(); j++) {
				if(s.charAt(j) != s.charAt(i)) break;
			}
			count += 1;
			i = j - 1;
		}
		return (double) (s.length()) / (double) count;
	}
}

// Powered by FileEdit