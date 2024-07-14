// 2013-02-21T21:13:24+01:00
import java.util.*;
import java.math.*;

public class ExerciseMachine {
	public int getPercentages(String time) {
		int all = (toi(time.substring(0, 2)) * 1200) + (toi(time.substring(3, 5)) * 60) + toi(time.substring(6, 8));
		int ans = 0;

		for(int i = 1; i < all; i++) {
			double perc = (i * 100.0) / all;
			if(Math.floor(perc) == perc) ans += 1;
		}

		return ans;
	}
	int toi(String s) {
		return Integer.parseInt(s);
	}
}


// Powered by FileEdit