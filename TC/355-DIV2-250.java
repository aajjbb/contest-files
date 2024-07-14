// 08-30-2012 20:38:53+01:00	Submit	aajjbb	250	247.75
import java.util.*;

public class ValueAddedTax {
	public double calculateFinalPrice(String product, int price, String[] food) {
		boolean ok = false;

		for(String s: food) {
			if(s.equals(product)) {
				ok = true; break;
			}
		}
		return ok ? (double) (price * 10.0 / 100.0) + price : (double) (price * 18.0 / 100.0) + price;
	}
}

// Powered by FileEdit