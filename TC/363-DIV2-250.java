// 06-10-2013 04:12:47+01:00	Submit	aajjbb	250	223.69
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class MirroredClock
{
	public String whatTimeIsIt(String time)
	{
		int h = Integer.parseInt(time.split(":")[0]); h = 12 - h; if (h == 12) h = 0;
		int m = Integer.parseInt(time.split(":")[1]); m = 60 - m; if (m == 60) m = 0;

		if (m > 0) h -= 1;
		if (h < 0) h = 11;

		String ans = "";

		ans += h; if (h < 10) ans = "0" + ans;
		ans += ":";
		if (m < 10) ans += "0"; ans += m;

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!