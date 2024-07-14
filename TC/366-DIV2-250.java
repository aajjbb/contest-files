// 09-03-2012 22:40:16+01:00	Submit	aajjbb	250	238.63
import java.util.*;
import java.math.*;

public class SerialNumbers {
	public String[] sortSerials(String[] serialNumbers) {
		int n = serialNumbers.length;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(!cmp(serialNumbers[i], serialNumbers[j])) {
					String tmp = serialNumbers[i];
					serialNumbers[i] = serialNumbers[j];
					serialNumbers[j] = tmp;
				}
			}
		}
		return serialNumbers;
	}
	boolean cmp(String a, String b) {
		if(a.length() != b.length()) return a.length() < b.length();
		int sumA = 0, sumB = 0;
		for(int i = 0; i < a.length(); i++) {
			if(a.charAt(i) >= '0' && a.charAt(i) <= '9') sumA += a.charAt(i) - '0';
			if(b.charAt(i) >= '0' && b.charAt(i) <= '9') sumB += b.charAt(i) - '0';
		}
		if(sumA != sumB) return sumA < sumB;
		return a.compareTo(b) < 0;
	}
}


// Powered by FileEdit