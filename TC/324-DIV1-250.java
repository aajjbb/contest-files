// 09-06-2013 03:36:07+01:00	Submit	aajjbb	250	207.98
import java.util.*;
import java.math.*;

public class PalindromeDecoding {
	public String decode(String code, int[] position, int[] length) {
		int i;

		for (i = 0; i < position.length; i++) {
			code = code.substring(0, position[i] + length[i]) + rev(code.substring(position[i], position[i] + length[i])) + code.substring(position[i] + length[i]);
		}

		return code;
	}

	public String rev(String str) {
		return new StringBuilder(str).reverse().toString();
	}
}

// Powered by FileEdit