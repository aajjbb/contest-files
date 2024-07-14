// 10-11-2012 04:08:48+01:00	Submit	aajjbb	250	245.13
using System;
using System.Collections;

public class FuelConsumption {
	public double maximalDistance(int[] velocities, int[] consumptions, int fuel) {
		double ans = 0.0;

		for(int i = 0; i < velocities.Length; i++) {
			ans = Math.Max(ans, (double) velocities[i] * fuel / consumptions[i]);
		}

		return ans;
	}
}


// Powered by FileEdit