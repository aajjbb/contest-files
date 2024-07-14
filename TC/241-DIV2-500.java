// 01-09-2012 17:02:36+01:00	Submit	aajjbb	500	150.00
import java.util.*;

public class ReportAccess {
	public String[] whoCanSee(String[] userNames, String[] allowedData, String[] reportData) {
		List<String> ans = new ArrayList<String>();

		for(int i = 0; i < userNames.length; i++) {
			int got = 0;
			String[] m = allowedData[i].split("\\s");
			int j;
			for(j = 0; j < reportData.length; j++) {
				boolean ok = false;
				for(int k = 0; k < m.length; k++) {
					if(m[k].equals(reportData[j])) {
						got++;
						ok = true;
					}
				}
				if(!ok) break;
			}
			if(j == reportData.length) {
				ans.add(userNames[i]);
			}
		}

		String[] ret = new String[ans.size()];

		for(int i = 0; i < ret.length; i++) {
			ret[i] = ans.get(i);
		}
		Arrays.sort(ret);
		return ret;
	}
}

// Powered by FileEdit