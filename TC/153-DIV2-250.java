// 2012-10-03T12:37:45+01:00
import java.util.*;
import java.math.*;

public class MostProfitable {
	public String bestItem(int[] costs, int[] prices, int[] sales, String[] items) {
		int index = -1, best = Integer.MIN_VALUE;

		for(int i = 0; i < costs.length; i++) {
			int profit = (prices[i] - costs[i]) * sales[i];
			if(profit > best) {
				best = profit;
				index = i;
			}
		}
		return best > 0 ? items[index] : "";
	}
}


// Powered by FileEdit