// 01-13-2013 02:04:43+01:00	Submit	aajjbb	250	246.21
/*
aajjbb
*/
import java.util.*;
import java.math.*;

public class AccountBalance {
	public int processTransactions(int startingBalance, String[] transactions) {
		for(int i = 0; i < transactions.length; i++) {
			String op = transactions[i].split("\\s")[0];
			int amount = Integer.parseInt(transactions[i].split("\\s")[1]);

			if(op.equals("C")) {
				startingBalance += amount;
			} else {
				startingBalance -= amount;
			}
		}
		return startingBalance;
	}
}


// Powered by FileEdit