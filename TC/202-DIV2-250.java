// 09-06-2012 14:32:46+01:00	Submit	aajjbb	250	247.58
import java.util.*;
import java.math.*;

public class LetterStrings {
	public int sum(String[] s) {
		int ans = 0;
		for(int i = 0; i < s.length; i++) {
			s[i] = s[i].replaceAll("-", "");
			ans += s[i].length();
		}
		return ans;
	}
}


// Powered by FileEdit
