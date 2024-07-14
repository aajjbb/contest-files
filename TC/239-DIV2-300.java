// 09-11-2012 12:37:10+01:00	Submit	aajjbb	300	267.39
import java.util.*;
import java.math.*;

public class Barbecue {
	public int eliminate(int n, int[] voter, int[] excluded) {
		int ans = -1;
		int[] v = new int[n], count = new int[n];
		for(int i = 0; i < voter.length; i++) {
			count[voter[i]] += 1;
			v[excluded[i]] += 1;
		}
		int max = 0;
		for(int i = 0; i < n; i++) {
			if(v[i] > max || (ans != -1 && v[i] == max && count[i] > count[ans])) {
				max = v[i];
				ans = i;
			}
		}
		return ans == -1 ? 0 : ans;
	}
}


// Powered by FileEdit