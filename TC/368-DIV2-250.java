// 09-25-2013 00:34:43+01:00	Submit	aajjbb	300	90.00
import java.util.*;
import java.math.*;

public class PirateTreasure {
	public double getDistance(int[] steps, String[] directions) {
		int i, N = steps.length;

		double x = 0.0;
		double y = 0.0;

		double C = Math.sqrt(2.0) / 2.0;

		for (i  = 0; i < N; i++) {
			if (directions[i].equals("NORTH")) {
				y -= steps[i];
			} else if (directions[i].equals("SOUTH")) {
				y += steps[i];
			} else if (directions[i].equals("EAST")) {
				x += steps[i];
			} else if (directions[i].equals("WEST")) {
				x -= steps[i];
			} else if (directions[i].equals("NORTHEAST")) {
				x += C * steps[i];
				y -= C * steps[i];
			} else if (directions[i].equals("NORTHWEST")) {
				x -= C * steps[i];
				y -= C * steps[i];
			} else if (directions[i].equals("SOUTHEAST")) {
				x += C * steps[i];
				y += C * steps[i];
			} else if (directions[i].equals("SOUTHWEST")) {
				x -= C * steps[i];
				y += C * steps[i];
			}
		}

		return Math.sqrt(x * x + y * y);
	}
}

// Powered by FileEdit