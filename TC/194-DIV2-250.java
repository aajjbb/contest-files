// 09-13-2011 14:05:14+01:00	Submit	aajjbb	250	247.30
import java.util.*;

public class Soccer {
	public int maxPoints(int[] wins, int[] ties) {
		int max = -1;

		for(int i = 0; i < wins.length; i++) {
			max = Math.max(max, (wins[i] * 3) + (ties[i] * 1));
		}
		return max;
	}
}

// Powered by FileEdit