// 11-04-2011 11:17:24+01:00	Submit	aajjbb	250	113.52
import java.util.*;

public class EratosthenSieve2 {
	public int nthElement(int n) {
		List<Integer> list = new LinkedList<Integer>();

		for(int i = 1; i <= 1000; i++) {
			list.add(i);
		}

		for(int i = 2; i <= 10; i++) {
			for(int j = list.size() - 1; j >= 0; j--) {
				if((j + 1) % i == 0) {
					list.remove(j);
				}
			}
		}
		return list.get(n - 1);
	}
}

// Powered by FileEdit
