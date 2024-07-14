// 2011-08-17T13:37:41+01:00
import java.util.*;

public class SimpleCardGame {
	public int whoIsTheWinner(int[] points) {
		List<Integer> loser = new ArrayList<Integer>();
		List<Integer> winner = new ArrayList<Integer>();
		List<Integer> exceed = new ArrayList<Integer>();

		for(int i = 0; i < points.length; i++) {
			if(points[i] < 21) {
				loser.add(points[i]);
			} else if(points[i] == 21) {
				winner.add(points[i]);
			} else {
				exceed.add(points[i]);
			}
		}

		if(winner.size() >= 2 || loser.size() == 0 && winner.size() == 0) {
			return -1;
		} else if(winner.size() == 1) {
			for(int i = 0; i < points.length; i++) {  if(points[i] == winner.get(0)) return i; }
		} else if(winner.size() == 0 && exceed.size() == 0) {
			List<Integer> temp = loser;

			Collections.sort(temp);

			int max = temp.get(temp.size() - 1);
			int nums = 0;
			int ret = 0;

			for(int i = 0; i < points.length; i++) {
				if(points[i] == max) {
					ret = i;
					nums++;
				}
			}

			if(nums == 1) {
				return ret;
			} else {
				return -1;
			}
		} else if(loser.size() > 0 && winner.size() == 0 && exceed.size() > 0) {
			List<Integer> temp = loser;

			Collections.sort(temp);
			int max = temp.get(temp.size() - 1);
			int nums = 0;
			int ret = 0;

			for(int i = 0; i < points.length; i++) {
				if(points[i] == max) {
					ret = i;
					nums++;
				}
			}

			if(nums == 1) {
				return ret;
			} else {
				return -1;
			}
		}
		return -1;
	}
}

// Powered by FileEdit