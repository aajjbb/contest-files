// 11-24-2011 01:32:07+01:00	Submit	aajjbb	1000	300.00
import java.util.*;

public class AutoMarket {
	public int maxSet(int[] cost, int[] features, int[] fixTimes) {
		List<Car> list = new LinkedList<Car>();
		int N = cost.length, res = 1;

		int[] dp = new int[1 << 16];

		for(int i = 0; i < N; i++) { list.add(new Car(cost[i], features[i], fixTimes[i])); }

		Collections.sort(list);

		dp[0] = 1;

		for(int i = 1; i < N; i++) {
			dp[i] = 1;
			for(int j = 0; j < i; j++) {
				if(list.get(i).cost > list.get(j).cost && list.get(i).features < list.get(j).features && list.get(i).fix > list.get(j).fix) {
					dp[i] = Math.max(dp[i], dp[j] + 1);
				}
			}
			res = Math.max(res, dp[i]);
		}
		return res;
	}
}

class Car implements Comparable<Car> {
	int cost;
	int features;
	int fix;

	public Car(int cost, int features, int fix) {
		this.cost = cost;
		this.features = features;
		this.fix = fix;
	}

	public int compareTo(Car o) {
		if(o.cost > this.cost) {
			return -1;
		} else {
			return 1;
		}
	}

}


// Powered by FileEdit
