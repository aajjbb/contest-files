// 10-13-2012 19:28:39+01:00	Submit	aajjbb	250	191.48
import java.util.*;

public class Rounder {
	public int round(int n, int b) {
		if(n % b == 0) return n;
		for(int less = n - 1, more = n + 1; ;) {
			if(more % b == 0) return more;
			if(less % b == 0) return less;
			if(less - 1 >= 0) less -= 1;
			more += 1;
		}
	}
}


// Powered by FileEdit