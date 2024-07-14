// 2011-07-27T20:44:54+01:00
import java.util.*;

public class HowManyBirthdays {
	public String[] getList(String[] friends, String today) {
		List<String> list = new ArrayList<String>();

		String[] todayArray = today.split("\\s");

		for(int i = 0; i < friends.length; i++) {
			String[] temp = friends[i].split("\\s");
			if(todayArray[0].equals(temp[1]) && todayArray[1].equals(temp[2])) {
				list.add(temp[0]);
			}
		}
		Collections.sort(list);
		String[] ret = new String[list.size()];

		for(int i = 0; i < list.size(); i++) {
			ret[i] = list.get(i);
		}
		return ret;
	}
}

// Powered by FileEdit
