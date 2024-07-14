// 01-08-2013 18:21:03+01:00	Submit	aajjbb	250	245.03
import java.util.*;
import java.math.*;

public class ProfitCalculator {
	public int percent(String[] items) {
		double all = 0.0, perc = 0.0;

		for(String str: items) {
			String[] tmp = str.split("\\s");
			all += Double.parseDouble(tmp[0]);
			perc += Double.parseDouble(tmp[1]);
		}
		return (int) ((all - perc) * 100.0 / (double) all);
	}
}


// Powered by FileEdit