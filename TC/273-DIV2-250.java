// 07-10-2011 01:30:16+01:00	Submit	aajjbb	250	201.90
import java.util.*;

public class AimToTen {
	public int need(int[] marks) {
		double tot = 0;
		int div = marks.length;

		for(int i : marks) {
			tot += i;
		}

		if((tot / div) >= 9.5) {
			return 0;
		} else {
			double media = tot / div;
			int inv = 0;
			while(media < 9.5) {
				tot += 10.0;
				div++;
				inv++;
				media = tot / div;
			}
			return inv;
		}
	}
}

// Powered by FileEdit