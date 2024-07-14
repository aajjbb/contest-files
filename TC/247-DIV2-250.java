// 09-23-2013 01:45:14+01:00	Submit	aajjbb	250	242.96
import java.util.*;
import java.math.*;

public class TriangleType {
	public String type(int a, int b, int c) {
		int[] side = {a, b, c};

		Arrays.sort(side);

		if (side[0] + side[1] <= side[2]) return "IMPOSSIBLE";

		if (side[0] * side[0] + side[1] * side[1] == side[2] * side[2]) {
			return "RIGHT";
		} else if (side[0] * side[0] + side[1] * side[1] < side[2] * side[2]) {
			return "OBTUSE";
		} else {
			return "ACUTE";
		}
	}
}

// Powered by FileEdit