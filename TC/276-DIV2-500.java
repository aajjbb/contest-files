// 12-17-2013 16:09:41+01:00	Submit	aajjbb	500	386.72
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class VolumeDiscount {
	public final int INF = (1 << 25);
	public int[][] dp = new int[10][200];

	public int N;

	public int func(int id, int qt, String[] priceList) {
		if (qt <= 0) {
			return 0;
		} else if (id == N) {
			if (qt <= 0) {
				return 0;
			} else {
				return INF;
			}
		} else {
			if (dp[id][qt] == -1) {
				int i;
				int j;

				dp[id][qt] = func(id + 1, qt, priceList);

				for (i = id; i < N; i++) {
					int quantity = Integer.parseInt(priceList[i].split(" ")[0]);
					int price = Integer.parseInt(priceList[i].split(" ")[1]);

					for (j = 1; ; j++) {
						dp[id][qt] = min(dp[id][qt], price * j + func(id + 1, qt - quantity * j, priceList));

						if (qt - quantity * j <= 0) {
							 break;
						}
					}
				}
			}
			return dp[id][qt];
		}
	}

	public int bestDeal(String[] priceList, int quantity) {
		int i;

		N = priceList.length;

		for (i = 0; i < N; i++) {
			Arrays.fill(dp[i], -1);
		}


		return func(0, quantity, priceList);
	}
}

//Powered by [KawigiEdit] 2.0!
