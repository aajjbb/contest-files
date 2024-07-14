// T2011-07-27T20:07:12+01:00
import java.util.*;

public class TrafficReport {
	public int bestRoute(String[] route, String[] report) {
		int way = 0;
		Set<String> set = new HashSet<String>();

		for(int i = 0; i < route.length; i++) {
			String[] temp = route[i].split("\\s");
			set.add(temp[1]);
			way += Integer.parseInt(temp[0]);
		}

		for(int i = 0; i < report.length; i++) {
			String[] temp = report[i].split("\\s");
			if(set.contains(temp[1])) {
				way += Integer.parseInt(temp[0]);
			}
		}
		return way;
	}
}

// Powered by FileEdit