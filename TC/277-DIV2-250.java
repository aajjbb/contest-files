// 09-12-2012 13:43:49+01:00	Submit	aajjbb	250	239.07
import java.util.*;
import java.math.*;

public class SandwichBar {
	public int whichOrder(String[] available, String[] orders) {
		available = unique(available);
		for(int i = 0; i < orders.length; i++) {
			String[] x = unique(orders[i].split("\\s"));
			int count = 0;
			for(int j = 0; j < available.length; j++) {
				for(int k = 0; k < x.length; k++) {
					if(x[k].equals(available[j])) {
						count += 1;
						break;
					}
				}
			}
			if(count == x.length) return i;
		}
		return -1;
	}
	public String[] unique(String[] s) {
		Set<String> tmp = new HashSet<String>();
		for(String x: s) tmp.add(x);
		String[] ans = new String[tmp.size()];
		int ind = 0;
		for(String x: tmp) {
			ans[ind++] = x;
		}
		return ans;
	}
}


// Powered by FileEdit