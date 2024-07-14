// 09-19-2012 13:31:41+01:00	Submit	aajjbb	250	173.38
import java.util.*;
import java.math.*;

public class CarBuyer {
	public double lowestCost(String[] cars, int fuelPrice, int annualDistance, int years) {
		double total = Double.MAX_VALUE;

		for(int i = 0; i < cars.length; i++) {
			String[] str = cars[i].split("\\s");
			double cost = (double) tInt(str[0]) + (years*tInt(str[1])) + (double)(years*fuelPrice*annualDistance/tInt(str[2]));
			if(cost < total) {
				total = cost;
			}
		}
		return total;
	}
	public double tInt(String s) { return Double.parseDouble(s); }
}


// Powered by FileEdit