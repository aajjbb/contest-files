// 10-14-2012 03:15:13+01:00	Submit	aajjbb	250	232.27
import java.util.*;

public class LevelUp {
	public int toNextLevel(int[] expNeeded, int received) {
		for(int i = 0; i < expNeeded.length; i++) {
			if(expNeeded[i] - received > 0) {
				return expNeeded[i] - received;
			}
		}
		return 0;
	}
}


// Powered by FileEdit
