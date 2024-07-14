// 06-21-2011 05:07:55	Submit	aajjbb	250	75.00
import java.util.*;

public class RussianSpeedLimits {
	public int getCurrentLimit(String[] signs) {
		int city = 0;
		String ret = "";

		for(String i: signs) {
			if(i.equals("city")) {
				city++;

				if(isPar(city)) {
					ret = "60";
					continue;
				} else {
					ret = "90";
					continue;
				}
			} else if(i.equals("default")) {
				if(isPar(city)) {
					ret = "60";
					continue;
				} else {
					ret = "90";
					continue;
				}
			} else {
				ret = i;
			}
		}
		return Integer.parseInt(ret);
	}

	public boolean isPar(int i) {
		if(i % 2 == 0) return true;
		return false;
	}
}


// Powered by FileEdit