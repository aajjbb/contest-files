import java.util.*;

public class QueryFilter {
	public String[] preprocess(String query, String[] common) {
		Set<String> set = new HashSet<String>();
		Set<String> aux = new HashSet<String>();
		
		String[] tokens = query.split("\\s");
		
		for(String i: common) aux.add(i);
		
		for(String i: tokens) {
			if(!aux.contains(i)) {
				set.add(i);	
			}
		}
		String[] ret = new String[set.size()];
		int temp = 0;
		for(String i: set) {
			ret[temp] = i;
			temp++;
		}
		Arrays.sort(ret);
		return ret;
	}
}