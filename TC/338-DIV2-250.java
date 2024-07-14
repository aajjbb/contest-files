// 11-16-2012 01:02:27+01:00	Submit	aajjbb	250	237.87
import java.util.*;

public class BinaryIncrementation {
	public String plusOne(String x) {
		int tmp = Integer.parseInt(x,2) + 1;
		return Integer.toBinaryString(tmp);
	}
}

// Powered by FileEdit