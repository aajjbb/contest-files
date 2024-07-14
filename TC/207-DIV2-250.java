// 02-24-2013 18:52:58+01:00	Submit	aajjbb	250	193.97
import java.util.*;
import java.math.*;

public class TransportCounting {
	public int countBuses(int speed, int[] positions, int[] velocities, int time) {
		int ans = 0, N = positions.length;
		int my = speed * time;

		for(int i = 0; i < N; i++) {
			if(positions[i] == 0) {
				ans += 1;
				continue;
			}
			int bus = velocities[i] * time;
			if(my >= bus + positions[i]) ans += 1;
		}

		return ans;
	}
}


// Powered by FileEdit