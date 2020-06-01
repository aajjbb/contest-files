// 10-07-2011 23:09:30
import java.util.*;

public class MissingDigits {
	public String isAllowed(int[] notAllowed, int roomNumber) {
		
		String test = ""+roomNumber;
		
		for(int i = 0; i < notAllowed.length; i++) {
			if(test.contains(i+""+notAllowed[i])) {
				return "NO";
			}
		}
		return "YES";
	}
}

// Powered by FileEdit
