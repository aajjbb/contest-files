// 2013-04-07 01:34:38
import java.util.*;
import java.math.*;

public class FlatCatsBreeding {
	public int days(int D, int K, int T) {
		int ans = 0, kitties = 1;

		while(kitties < T) {
			kitties = kitties + (kitties * K);
			ans += 1;
		}

		return ans * D;
	}
}

// Powered by FileEdit