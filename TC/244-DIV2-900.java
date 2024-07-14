// 09-22-2011 20:11:24+01:00	Submit	aajjbb	900	312.04
import java.util.*;

public class CircleDance {
	public int arrangeDancers(int[] h) {
		List<Integer> list = new LinkedList<Integer>();
		Arrays.sort(h);

		for(int i = 0; i < h.length; i++) {
			if(i % 2 != 0) {
				list.add(0, h[i]);
			} else {
				list.add(h[i]);
			}
		}
		 return max(list);
	}
	public int max(List<Integer> list) {
		int max = 0;
		for(int i = 1; i < list.size(); i++) {
			max = Math.max(max, Math.abs(list.get(i - 1) - list.get(i)));
		}
		return max;
	}
}