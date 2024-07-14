// 12-25-2011 18:09:35+01:00	Submit	aajjbb	250	185.66
import java.util.*;

public class MedianProcess {
	public int getScore(int[] values) {
		List<Integer> list = new ArrayList<Integer>();
		for(int i: values) list.add(i);

		return computeArray(list);
	}
	public int computeArray(List<Integer> list) {
		if(list.size() == 0) return 0;
		Collections.sort(list);
		int tmp = 0;
		if(list.size() % 2 == 0) {
			tmp = list.get(list.size() - 1);
			list.remove(list.size() - 1);
			return computeArray(list) - tmp;
		} else {
			tmp = list.get(((list.size() + 1) / 2) - 1);
			list.remove(((list.size() + 1) / 2) - 1);
			return tmp + computeArray(list);
		}
	}
}


// Powered by FileEdit