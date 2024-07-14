// 10-13-2011 00:48:17+01:00	Submit	aajjbb	250	236.52
import java.util.*;
public class WaiterTipping {
	public int maxPercent(int total, int taxPercent, int money) {
		int rate = 0;
		int i = -1;
		while(rate <= money) {
			i++;
			rate = total + (int) Math.floor(total * taxPercent / 100) + (int) Math.floor(total*i/100);
		}
		return i == 0 ? -1 : i - 1;
	}
}


// Powered by FileEdit