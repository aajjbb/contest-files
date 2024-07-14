// 10-18-2012 14:03:49+01:00	Submit	aajjbb	250	213.95
import java.util.*;
import java.math.*;

public class AzimuthMonitoring {
	public int getAzimuth(String[] instructions) {
		int now = 0;

		for(String str: instructions) {
			if(str.equals("HALT")) break;
			if(str.equals("TURN AROUND")) {
				now = (now + 180) % 360;
			} else {
				String[] split = str.split("\\s");
				if(split[0].equals("RIGHT")) {
					if(split.length == 2) {
						now = (now + Integer.parseInt(split[1])) % 360;
					} else {
						now = (now + 90) % 360;
					}
				} else {
					if(split.length == 2) {
						now = now - Integer.parseInt(split[1]) < 0 ? 360 + now - Integer.parseInt(split[1]) : now - Integer.parseInt(split[1]);
					} else {
						now = now - 90 < 0 ? 360 + now - 90 : now - 90;
					}
				}
			}
		}

		return now;
	}
}


// Powered by FileEdit