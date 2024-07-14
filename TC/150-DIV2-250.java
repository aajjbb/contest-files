// 2012-10-01T18:44:52+01:00
import java.util.*;
import java.math.*;

public class WidgetRepairs {
	public int days(int[] arrivals, int numPerDay) {
		int days = 0, amount = 0;
		for(int i = 0; i < arrivals.length; i++) {
			amount += arrivals[i];
			if(amount > 0) days += 1;
			amount = Math.max(0, amount - numPerDay);
		}
		while(amount > 0) {
			days += 1;
			amount -= numPerDay;
		}
		return days;
	}
}


// Powered by FileEdit