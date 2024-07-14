// 09-06-2012 13:46:11+01:00	Submit	aajjbb	250	237.53
import java.util.*;
import java.math.*;

public class SubstitutionCode {
	public int getValue(String key, String code) {
		String ans = "";
		for(char c: code.toCharArray()) {
			if(key.contains(""+c)) {
				ans += key.indexOf(c) + 1 == 10 ? 0 : key.indexOf(c) + 1;
			}
		}
		return Integer.parseInt(ans);
	}
}


// Powered by FileEdit