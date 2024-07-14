// 2013-03-09T03:44:26+01:00
import java.util.*;
import java.math.*;

public class PartySeats {
	public String[] seating(String[] attendees) {
		List<String> boy = new ArrayList<String>(), girl = new ArrayList<String>();

		for(int i = 0; i < attendees.length; i++) {
			String[] now = attendees[i].split("\\s");
			if(now[1].equals("boy")) {
				boy.add(now[0]);
			} else {
				girl.add(now[0]);
			}
		}
		if(boy.size() != girl.size() || boy.size() < 2) return new String[] {};

		Collections.sort(boy);
		Collections.sort(girl);

		String[] ans = new String[boy.size() * 2 + 2];

		ans[0] = "HOST";
		ans[ans.length/2] = "HOSTESS";

		int ib = 0, ig = 0, id = 1;

		for(int i = 0; i < boy.size()/2; i++) {
			ans[id++] = girl.get(ig++);
			ans[id++] = boy.get(ib++);
		}
		id++;
		for(int i = 0; i < boy.size()/2; i++) {
			ans[id++] = boy.get(ib++);
			ans[id++] = girl.get(ig++);
		}
		return ans;
	}
}

// Powered by FileEdit
