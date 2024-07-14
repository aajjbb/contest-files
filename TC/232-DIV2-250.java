// 12-18-2013 16:23:38+01:00	Submit	aajjbb	250	235.33
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BritishCoins {
	public int[] coins(int pence) {
		int[] ans = new int[3];

		ans[0] = pence / (20 * 12);

		pence -= ans[0] * (20  * 12);

		ans[1] = pence / 12;

		pence %= 12;

		ans[2] = pence;

		return ans;
	}
}
//Powered by [KawigiEdit] 2.0!
