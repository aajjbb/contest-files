// 09-21-2012 18:36:26+01:00	Submit	aajjbb	250	203.53
import java.util.*;
import java.math.*;

public class Stairs {
	public int designs(int maxHeight, int minWidth, int totalHeight, int totalWidth) {
		int ans = 0;
		for(int i = 1; i <= maxHeight; i++) {
			if(totalHeight % i != 0) continue;
			int width = totalHeight/i - 1;
			if(width != 0 && totalWidth / width >= minWidth && totalWidth % width == 0) ans += 1;
		}
		return ans;
	}
}

// Powered by FileEdit