// 06-24-2013 18:53:21+01:00	Submit	aajjbb	250	139.71
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class DinkyFish
{
	private final double EPS = 1e-4;
	public int monthsUntilCrowded(int tankVolume, int maleNum, int femaleNum)
	{
		int T = 0;

		for ( ; ; T++) {
			int all = maleNum + femaleNum;
			int couples = Math.min(maleNum, femaleNum);

			double ratio = (double) tankVolume / (double) all;

			if (ratio + EPS < 0.5) return T;

			maleNum += couples;
			femaleNum += couples;
		}

	}
}
//Powered by [KawigiEdit] 2.0!