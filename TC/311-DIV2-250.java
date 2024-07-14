// 09-09-2012 02:40:38+01:00	Submit	aajjbb	250	247.41
import java.util.*;

public class EscapeFromRectangle {
	public int shortest(int x, int y, int w, int h) {
		return Math.min(x, Math.min(y, Math.min(w - x, h - y)));
	}
}


// Powered by FileEdit