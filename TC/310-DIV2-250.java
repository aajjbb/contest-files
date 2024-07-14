// 02-22-2013 16:15:42+01:00	Submit	aajjbb	250	209.95
import java.util.*;
import java.math.*;

public class MeasuringTemperature {
	int[] differ = {-2, -1, 1, 2};
	public double averageTemperature(int[] values) {
		double all = 0.0, count = 0.0;

		for(int i = 0; i < values.length; i++) {
			if(values[i] < -273) continue;
			int ok = 0;
			for(int j = 0; j < 4; j++) {
				int index = i + differ[j];
				if(index >= 0 && index < values.length) {
					if(Math.abs(values[i] - values[index]) <= 2) ok += 1;
				}
			}
			if(ok > 0) {
				count += 1.0;
				all += (double) values[i];
			}
		}
		if(count == 0) return -300.0;
		else return (double) all / (double) count;
	}
}


// Powered by FileEdit