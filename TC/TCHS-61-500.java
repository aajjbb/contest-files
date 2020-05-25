import java.util.*;
import java.math.*;

public class ProductOfDigits {
	public int smallestNumber(int N) {
		if(N == 1) return 1;
		
		int ans = 0;
		for(int x = 9; x > 1; x--) {
			while(N % x == 0) {
				ans += 1;
				N /= x;
			}
		}
		if(N > 1) return -1;
		return ans;
	}	
}

// Powered by FileEdit
