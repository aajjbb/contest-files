// 2012-10-29T02:06:09+01:00
/*
aajjbb
*/
import java.util.*;
import java.math.*;

public class FormatAmt {
	public String amount(int dollars, int cents) {
		String ans = "$";

		String decimal = "";
		int check = 0, _dollars = dollars;
		while(dollars > 0) {
			check += 1;
			decimal += dollars % 10;
			if(check % 3 == 0) decimal += ",";
			dollars /= 10;
		}
		decimal = new StringBuilder(decimal).reverse().toString();
		if(decimal.startsWith(",")) decimal = decimal.substring(1);
		if(_dollars == 0) ans += 0;
		ans += decimal + ".";
		if(cents < 10) ans += "0";
		ans += cents;
		return ans;
	}
}


// Powered by FileEdit