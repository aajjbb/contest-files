// 09-14-2011 15:45:04+01:00	Submit	aajjbb	250	200.71
import java.util.*;

public class CustomerStatistics {
	public String[] reportDuplicates(String[] c) {
		List<String> list = new ArrayList<String>();

		for(int i = 0; i < c.length; i++) {
			int p = 0;
			String a = c[i];
			for(int x = 0; x < c.length; x++) {
				if(c[x].equals(a)) {
					p++;
				}
			}
			if(p >= 2) {
				boolean flag = false;
				for(String s: list) {
					String[] xp = s.split(" ");
					if(xp[0].equals(a)) {
						flag = true;
					}
				}
				if(flag == false) {
					int temp = 0;
					for(int j = 0; j < c.length; j++) {
						String[] t = c[j].split(" ");
						if(t[0].equals(c[i])) {
							temp++;
						}
					}
					list.add(c[i] + " " + temp);
				}
			}
		}
		int i = 0;
		String[] ret = new String[list.size()];
		Collections.sort(list);
		for(String s: list) {
			ret[i] = s;
			i++;
		}
		return ret;
	}
}

// Powered by FileEdit