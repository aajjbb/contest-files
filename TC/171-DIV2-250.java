// 09-30-2012 00:55:11+01:00	Submit	aajjbb	250	219.43
import java.util.*;

public class RPG {
	public int[] dieRolls(String[] dice) {
		int[] ans = new int[3];
		double sum = 0.0;
		for(String str: dice) {
			String[] tmp = str.split("d");
			int amount = Integer.parseInt(tmp[0]);
			int values = Integer.parseInt(tmp[1]);

			ans[0] += 1 * amount;
			ans[1] += amount * values;
			sum += (double) ((values+1)/2.0) * amount;
		}

		ans[2] = (int) Math.floor(sum);

		return ans;
	}
}


// Powered by FileEdit