// 03-05-2012 20:08:17+01:00	Submit	aajjbb	1000	300.00
import java.util.*;

public class CalcButton {
	public String getDigits(String[] seq) {
		String ans = "000", all = "";
		int mx = -1;

		for(String s: seq) all += s;

		for(int i = 0; i < all.length() - 2; i++) {
			String tmp = all.substring(i, i + 3);
			int times = 0;
			for(int j = 0; j < all.length()-2; j++) {
				if(all.substring(j, j + 3).equals(tmp)) times++;
				j += 2;
			}
			if(times > mx ||(times == mx && tmp.compareTo(ans) < 0)) {
				ans = tmp;
				mx = times;
			}
		}
		return ans;
	}
}

// Powered by FileEdit