// 02-07-2013 13:17:59+01:00	Submit	aajjbb	250	246.35
/*
aajjbb
*/
import java.util.*;
import java.math.*;

public class UserName {
	public String newMember(String[] existingNames, String newName) {
		Set<String> set = new HashSet<String>();

		for(String s: existingNames) set.add(s);

		String now = newName;
		int counter = 1;

		while(set.contains(now)) {

			now = newName + (counter++);
		}
		return now;
	}
}

// Powered by FileEdit