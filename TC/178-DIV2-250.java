// 03-08-2013 16:38:41+01:00	Submit	aajjbb	250	222.13
import java.util.*;
import java.math.*;

public class SimpleCalculator {
	public int calculate(String input) {
		String[] num = input.split("[\\+\\-\\*\\/]");

		char op = ' ';
		for(int i = 0; i < input.length(); i++) if(!(input.charAt(i) >= '0' && input.charAt(i) <= '9')) {
			op = input.charAt(i);
			break;
		}
		int a = Integer.parseInt(num[0]), b = Integer.parseInt(num[1]);

		if(op == '+') return a + b;
		else if(op == '-') return a - b;
		else if(op == '*') return a * b;
		else return a / b;
	}
}


// Powered by FileEdit