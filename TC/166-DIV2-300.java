// 10-01-2012 04:19:24+01:00	Submit	aajjbb	300	284.04
import java.util.*;

public class Workshop {
	public int pictureFrames(int[] pieces) {
		int ans = 0, N = pieces.length;
		Arrays.sort(pieces);
		for(int i = 0; i < N; i++) {
			for(int j = i + 1; j < N; j++) {
				for(int k = j + 1; k < N; k++) {
					if(isPossible(pieces[i], pieces[j], pieces[k])) ans += 1;
				}
			}
		}
		return ans;
	}
	public boolean isPossible(int a, int b, int c) {
		return (a + b > c);
	}
}


// Powered by FileEdit
