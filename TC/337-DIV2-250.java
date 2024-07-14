// 09-12-2012 17:46:42+01:00	Submit	aajjbb	250	245.51
import java.util.*;
import java.math.*;

public class Palindromize2 {
	public String minChanges(String s) {
		int min = 0;
		char[] help = s.toCharArray();
		for(int i = 0; i < s.length(); i++) if(!(s.length() % 2 != 0 && i == (s.length() / 2))) {
			System.out.println(help[i] + " " + help[help.length - i - 1]);
			if(help[i] != help[help.length - i - 1]) {
				help[i] = cmin(help[i], help[help.length - i - 1]);
				help[help.length - i - 1] = cmax(help[help.length - i - 1], help[i]);
			}
		}
		return new String(help);
	}
	public char cmin(char a, char b) {
		return a < b ? a : b;
	}
	public char cmax(char a, char b) {
		return a < b ? b : a;
	}
}

// Powered by FileEdit