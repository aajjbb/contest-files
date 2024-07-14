// 2012-10-01T18:30:32+01:00
import java.util.*;
import java.math.*;

public class LCMRange {
	public int lcm(int first, int last) {
		int ans = first;
		for(int i = first + 1; i <= last; i++) {
			ans = _lcm(ans, i);
		}
		return ans;
	}
	public int gcd(int a, int b) {
		if(b == 0) return a;
		return gcd(b, a % b);
	}
	public int _lcm(int a, int b) {
		return a * b / gcd(a, b);
	}
}


// Powered by FileEdit