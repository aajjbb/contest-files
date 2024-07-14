// 10-01-2012 03:33:37+01:00	Submit	aajjbb	500	277.39
import java.util.*;

public class BirthNumbersValidator {
	public static int[] daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public String[] validate(String[] test) {
		int N = test.length;
		String[] ans = new String[N];

		Arrays.fill(ans, "NO");

		for(int i = 0; i < N; i++) {
			int day = Integer.parseInt(test[i].substring(4, 6));
			int month = Integer.parseInt(test[i].substring(2, 4));
			int year = Integer.parseInt(test[i].substring(0, 2));

			if(!isValidMonth(month) || !isValidDay(day, month - 1, year)) continue;

			if(isDivisible(Long.parseLong(test[i]))) {
				ans[i] = "YES";
			}
		}

		return ans;
	}

	public boolean isLeap(int year) {
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}

	public boolean isValidDay(int day, int month, int year) {
		if(month > 12) month -= 50;
		if(year >= 7) year += 1900; else year += 2000;
		int daysToCheck = isLeap(year) && month == 1 ? 29 : daysInMonths[month];
		return day >= 1 && day <= daysToCheck;
	}

	public boolean isValidMonth(int month) {
		return (month >= 1 && month <= 12) || (month >= 51 && month <= 62);
	}
	public boolean isDivisible(long n) {
		long a = 0, b = 0, ok = 1;
		while(n > 0) {
			long digit = (long) n % 10;
			if(ok == 1) {
				a += digit;
				ok = 0;
			} else {
				b += digit;
				ok = 1;
			}
			n /= 10;
		}
		return Math.abs(a - b) % 11 == 0 || Math.abs(a - b) == 0;
	}
}


// Powered by FileEdit