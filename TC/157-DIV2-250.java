// 2013-03-02T13:46:39+01:00
import java.util.*;

public class GuessTheNumber {
	public int noGuesses(int upper, int answer) {
		int low = 1, high = upper, mid, ct = 1;

		while(low <= high) {
			mid = (low + high) >> 1;
			if(mid == answer) return ct;
			if(mid > answer) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}

			ct += 1;
		}

		return ct;
	}
}