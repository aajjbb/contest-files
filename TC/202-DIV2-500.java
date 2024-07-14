// 10-03-2012 12:03:08+01:00	Submit	aajjbb	500	150.00
import java.util.*;
import java.math.*;

public class Hyphenated {
	public double avgLength(String[] lines) {
		int j;
		double words = 0.0, len = 0.0;

		String all = ""; for(String s: lines) all += s;

		for(int i = 0; i < all.length(); i++) {
			if(isLetter(all.charAt(i))) {
				int curr_len = 0;
				j = i;
				while(j < all.length() && isLetter(all.charAt(j))) {
					curr_len += 1;
					if(j + 1 < all.length() && all.charAt(j + 1) == '-' && in(lines, j) != in(lines, j + 2)) {
						j += 2;
					} else {
						j += 1;
					}
				}
				System.out.println(all.substring(i, j));
				i = j;
				words += 1.0;
				len += (double) curr_len;
			}
		}
		return (double) len / (double) words;
	}
	public boolean isLetter(char c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
	public int in(String[] words, int index) {
		int len = 0;
		for(int i = 0; i < words.length; i++) {
			len += words[i].length() - 1;
			if(len >= index) return i;
		}
		return -1;
	}
}


// Powered by FileEdit