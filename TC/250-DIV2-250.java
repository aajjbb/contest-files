// 10-29-2012 17:39:01+01:00	Submit	aajjbb	250	224.71
import java.util.*;
import java.math.*;

public class ColorCode {
	public long getOhms(String[] code) {
		int[] mult = new int[10], value = new int[10];
		long ans = 0;
		String[] names = new String[10];

		mult[0] = 1; value[0] = 0;
		for(int i = 1; i < 10; i++) {
			mult[i] = mult[i-1] * 10;
			value[i] = value[i-1] + 1;
		}

		names[0] = "black";
		names[1] = "brown";
		names[2] = "red";
		names[3] = "orange";
		names[4] = "yellow";
		names[5] = "green";
		names[6] = "blue";
		names[7] = "violet";
		names[8] = "grey";
		names[9] = "white";

		int last = -1;
		for(int i = 0; i < code.length; i++) {
			for(int j = 0; j < 10; j++) if(code[i].equals(names[j])) {
				if(i == 0) {
					last = value[j];
				} else if(i == 1) {
					ans += Integer.parseInt(last+""+value[j]);
				} else {
					ans *= (long) mult[j];
				}
			}
		}

		return ans;
	}
}

// Powered by FileEdit