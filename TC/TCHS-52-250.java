// 2011-08-22T19:05:06+01:00
import java.util.*;

public class TournamentJudging {
	public int getPoints(int[] rawScores, int[] conversionFactor) {
		int ret = 0;

		for(int i = 0; i < rawScores.length; i++) {
			double temp = (double) rawScores[i] / (double) conversionFactor[i];
			ret += temp + 0.5d;
		}

		return ret;
	}
}


// Powered by FileEdit
