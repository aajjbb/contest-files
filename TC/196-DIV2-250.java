// 02-24-2013 01:44:15+01:00	Submit	aajjbb	250	183.99
import java.util.*;
import java.math.*;

public class Education {
	public int minimize(String desire, int[] tests) {
		int sum = 0, low = got(desire);

		for(int i = 0; i < tests.length; i++) sum += tests[i];

		for(int i = 0; i <= 100; i++) {
			sum += i;
			int median = (int) Math.floor(sum / (tests.length + 1));
			if(median >= low) return i;
			sum -= i;
		}

		return -1;
	}
	public int got(String desire) {
		if(desire.equals("A")) return 90;
		else if(desire.equals("B")) return 80;
		else if(desire.equals("C")) return 70;
		return 60;
	}
}

// Powered by FileEdit