// 07-15-2012 17:20:18+01:00	Submit	aajjbb	500	484.29
import java.util.*;
import java.math.*;

public class ObtainingDigitK {
	public int minNumberToAdd(String originalNumber, int k) {
		BigInteger big = new BigInteger(originalNumber);

		for(int i = 0; ; i++) {
			String helper = big.toString();
			for(int j = 0; j < helper.length(); j++) {
				if(helper.charAt(j) - '0' == k) return i;
			}
			big = big.add(BigInteger.valueOf(1));
		}
	}
}


// Powered by FileEdit