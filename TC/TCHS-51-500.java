// 21-09-2011 13:22:44
import java.util.*;

public class AuctionHouse {
	public String[] getList(String[] bids) {
		Collection<String> items = new LinkedHashSet<String>();
		
		for(int i = 0; i < bids.length; i++) {
			String[] temp = bids[i].split("\\s");
			items.add(temp[1]);		
		}
		String[] ret = new String[items.size()];
		int a = 0;
		for(String i: items) {
			int max = -1;
			int p = 0;
			for(int j = 0; j < bids.length; j++) {
				String[] temp = bids[j].split("\\s");
				if(temp[1].equals(i)) {
					if(Integer.parseInt(temp[2]) > max) {
						max = Integer.parseInt(temp[2]);
						p = j;
					}
				}
			}
			String[] aux = bids[p].split("\\s");
			ret[a] = aux[0] + " got " + i;
			a++;
		}
		return ret;
	}
}
