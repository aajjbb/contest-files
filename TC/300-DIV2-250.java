// 09-09-2012 03:58:48+01:00	Submit	aajjbb	250	157.89
import java.util.*;

public class Taxi {
	public double maxDis(int maxX, int maxY, int taxiDis) {
		double maximal = -1.0;
		for(int x = 0; x <= taxiDis; x++) {
			int y = taxiDis - x;
			if(x + y == taxiDis && x <= maxX && y <= maxY) {
				maximal = Math.max(maximal, euclid(0, 0, x, y));
			}
		}
		return maximal;
	}
	public double euclid(int x1, int y1, int x2, int y2) {
		return (double) Math.hypot(x1 - x2, y1 - y2);
	}
	public int taxi(int x1, int y1, int x2, int y2) {
		return (int) Math.abs(x1 - x2) + (int) Math.abs(y1 - y2);
	}
}

// Powered by FileEdit