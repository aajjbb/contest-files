// 2012-09-30T02:04:21+01:00
import java.util.*;

public class BaseMystery {
	public int[] getBase(String equation) {
		List<Integer> validBases = new ArrayList<Integer>();

		for(int i = 2; i <= 20; i++) {
			if(isValid(equation, i)) validBases.add(i);
		}

		int[] ans = new int[validBases.size()];
		for(int i = 0; i < ans.length; i++) {
			ans[i] = validBases.get(i);
		}
		return ans;
	}
	public boolean isValid(String equation, int base) {
		String summand_a = equation.substring(0, equation.indexOf("+"));
		String summand_b = equation.substring(equation.indexOf("+") + 1, equation.indexOf("="));
		String answer = equation.substring(equation.indexOf("=") + 1);

		int a = toDecimal(summand_a, base);
		int b = toDecimal(summand_b, base);
		int ans = toDecimal(answer, base);

		if(a == Integer.MAX_VALUE || b == Integer.MAX_VALUE || ans == Integer.MAX_VALUE) return false;

		if(a + b == ans) {
			return true;
		}
		return false;
	}
	public int toDecimal(String n, int b) {
		int result = 0;
		int multiplier = 1;

	  	for(int i = n.length() - 1; i >= 0; i--) {
			int value = n.charAt(i) >= '0' && n.charAt(i) <= '9' ? n.charAt(i) - '0' : n.charAt(i) - 'A' + 10;
			if(value >= b) return (int) Integer.MAX_VALUE;
		    result += value * multiplier;
		    multiplier *= b;
   		}
		return result;
	}
}


// Powered by FileEdit