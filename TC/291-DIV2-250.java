// 09-23-2011 12:15:28+01:00	Submit	aajjbb	250	219.13
import java.util.*;

public class FarFromPrimes {
	public int count(int A, int B) {
		int sum = 0;
		for(int i = A; i <= B; i++) {
			if(isFar(i)) {
				sum++;
			}
		}
		return sum;
	}
	public boolean isFar(int n) {
		for(int i = n, j = n; i >= n - 10 && j <= n + 10; i--, j++) {
			if(isPrime(i) || isPrime(j)) {
				return false;
			}
		}
		return true;
	}
	public boolean isPrime (int n) {
   		if (n<=1) return false;
   		if (n==2) return true;
   		if (n%2==0) return false;
   		int m = (int) Math.sqrt(n);

   		for (int i=3; i<=m; i+=2)
    		if(n%i==0)
         		return false;

	   return true;
	}
}