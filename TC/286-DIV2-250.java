// 09-12-2012 18:53:37+01:00	Submit	aajjbb	250	225.65
import java.util.*;
import java.math.*;

public class CuttingPoles {
	public int countCuts(int[] poles) {
		int cuts = 0, n = poles.length;
		while(true) {
			Arrays.sort(poles);
			int media = mean(poles);
			if(poles[n-1] == media) break;
			poles[0] = poles[0] + (poles[n-1] - media);
			poles[n-1] = media;
			cuts += 1;
		}
		return cuts;
	}
	public int mean(int[] x) {
		int sum = 0;
		for(int i: x) sum += i;
		return (int) sum / x.length;
	}
}


// Powered by FileEdit