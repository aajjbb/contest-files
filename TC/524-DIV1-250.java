// 2019-11-27 - 14:06 - Pindamonhangaba/Brazil.

import java.math.*;

public class MagicDiamonds {
	public long minimalTransfer(long n) {
		if (n <= 3) return n;
		
		BigInteger curr_n = new BigInteger(""+n);
		
		if (curr_n.isProbablePrime(100)) {
			return 2;
		} else {		
			return 1;
		}
	}
}
